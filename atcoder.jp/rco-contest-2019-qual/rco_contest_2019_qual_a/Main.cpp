#include <bits/stdc++.h>
using namespace std;

class Timer {
public:
  inline void start() {
    startTime = std::chrono::system_clock::now();
  }
  void stop() {
    endTime = std::chrono::system_clock::now();
  }
  long long elapsedTime() {
    auto nowTime = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - startTime).count();
  }
  long long elapsedTimeUsec() {
    auto nowTime = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(nowTime - startTime).count();
  }
  long long startToEndTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
  }
  std::chrono::system_clock::time_point startTime;
  std::chrono::system_clock::time_point endTime;
};
uint32_t xor128(void) { 
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123; 
  uint32_t t;
 
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}

double l2(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct Node {
  int id;
  double f_d, b_d;
  Node *f, *b;
};

int main(void) {
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  Timer timer;
  timer.start();
  int N;
  cin >> N;
  vector<int> px(N), py(N);
  for (int i = 0; i < N; i++) {
    cin >> px[i] >> py[i];
  }

  int forward[201], backward[201];
  double dist[201][201], dist2[201][201];
  double allavg = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double d = l2(px[i], py[i], px[j], py[j]);
      dist[i][j] = d;
      dist[j][i] = d;
      dist2[i][j] = d * d;
      dist2[j][i] = d * d;
      allavg += d;
    }
  }
  allavg /= (N * (N - 1)) / 2;

  vector<vector<pair<double,int>>> es(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      // es[i].emplace_back( abs(dist[i][j] - allavg), j);
      es[i].emplace_back( dist[i][j], j);
    }
    sort(es[i].begin(), es[i].end());
  }

  int v = 0;
  double dsum = 0, d2sum = 0;
  vector<int> path(N);
  set<int> visited;
  visited.insert(v);
  for (int i = 0; i < N - 1; i++) {
    // cout << v << endl;
    path[i] = v;
    int next_v = -1;
    for (auto& data : es[v]) {
      // data.first;
      next_v = data.second;
      if (visited.find(next_v) == visited.end()) break;
    }
    visited.insert(next_v);
    dsum += dist[v][next_v];
    d2sum += dist2[v][next_v];
    v = next_v;
  }
  // cout << v << endl;
  path[N - 1] = v;

  dsum += dist[0][v];
  d2sum += dist2[0][v];
  double var = d2sum / N - pow((dsum / N), 2);
  double avg = dsum / N;
  double orgdsum = dsum;
  int trycount = 0, updatecount = 0;
  for (;;) {
    int a = xor128() % N;
    int b = xor128() % N;
    while (a == b) b = xor128() % N;
    dsum = d2sum = 0;

    swap(path[a], path[b]);
    for (int i = 1; i < N; i++) {
      dsum += dist[path[i]][path[i - 1]];
      d2sum += dist2[path[i]][path[i - 1]];
    }
    dsum += dist[path[N - 1]][path[0]];
    d2sum += dist2[path[N - 1]][path[0]];
    double newvar = d2sum / N - pow((dsum / N), 2);
    // timer.elapsedTime() < 1000 && orgdsum > dsum || 
    if (newvar < var) {
      // cerr << "update : " << var << " -> " << newvar << endl;
      // cerr << "update : " << dsum << " -> " << orgdsum << endl;
      var = newvar;
      avg = dsum / N;
      orgdsum = dsum;
    } else {
      swap(path[a], path[b]);
    }
    if (trycount % 1000 == 0) {
      if (timer.elapsedTime() >= 100) break;
    }
    trycount++;
  }

  for (;;) {
    for (int i = 0; i < N; i++) {
      int v1 = path[i];
      int v2 = path[(i + 1) % N];
      double mindiff = 1e8;
      int min_diff_id = -1;
      min_diff_id = xor128() % (N - 1);
      while (min_diff_id == i || min_diff_id == (i + 1) % N) {
        min_diff_id = xor128() % (N - 1);
      }

      // cerr << i << " " << min_diff_id << endl;
      if (i < min_diff_id) {
        reverse(path.begin() + i + 1, path.begin() + min_diff_id);
      } else {
        reverse(path.begin() + min_diff_id + 1, path.begin() + i);
      }

      dsum = d2sum = 0;
      for (int i = 1; i < N; i++) {
        dsum += dist[path[i]][path[i - 1]];
        d2sum += dist2[path[i]][path[i - 1]];
      }
      dsum += dist[path[N - 1]][path[0]];
      d2sum += dist2[path[N - 1]][path[0]];
      double newvar = d2sum / N - pow((dsum / N), 2);
      if (newvar < var) {
        var = newvar;
        // cerr << "update : " << var << " -> " << newvar << endl;
      } else {
        if (i < min_diff_id) {
          reverse(path.begin() + i + 1, path.begin() + min_diff_id);
        } else {
          reverse(path.begin() + min_diff_id + 1, path.begin() + i);
        }
      }
    }
    if (timer.elapsedTime() >= 1995) break;
  }

  for (int i = 0; i < N; i++) {
    cout << path[i] << endl;
  }
  cerr << trycount << endl;
  cerr << (int)ceil(1e6 / (1 + var)) << endl;
  cerr << timer.elapsedTime() << endl;

  return 0;
}