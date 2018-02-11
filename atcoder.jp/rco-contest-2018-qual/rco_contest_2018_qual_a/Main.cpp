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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int used[50][50];
int bfs(int x, int y, vector<string>& map) {
  queue<int> qx, qy, qk;
  memset(used, 0, sizeof(used));
  qx.push(x);
  qy.push(y);
  qk.push(-1);
  bool firstMove = true;
  used[y][x] = 1;
  while(!qx.empty()) {
    int nowx = qx.front();qx.pop();
    int nowy = qy.front();qy.pop();
    int firstk = qk.front();qk.pop();
    cerr << nowx << " " << nowy << " " << firstk << endl;
    for (int k = 0; k < 4; k++) {
      int nx = nowx + dx[k];
      int ny = nowy + dy[k];
      if (map[ny][nx] == '#' || map[ny][nx] == 'x') continue;
      if (used[ny][nx]) continue;
      used[ny][nx] = 1;
      if (map[ny][nx] == 'o') {
        if (firstMove) return k;
        else return firstk;
      }
      if (map[ny][nx] == '.') {
        qx.push(nx);
        qy.push(ny);
        if (firstMove) qk.push(k);
        else qk.push(firstk);
      }
    }
    firstMove = false;
  }
  return -1;
}

int main(void) {
  Timer timer;
  timer.start();
  
  int N, K, H, W, T;
  cin >> N >> K >> H >> W >> T;

  vector<vector<string>> maps(N, vector<string>(H));
  vector<int> coins(N);
  vector<int> traps(N);
  vector<int> px(N), py(N);

  for (int i = 0; i < N; i++) {
    for (int h = 0; h < H; h++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == '@') {
          py[i] = h; px[i] = j;
          s[j] = '.';
        }
        if (s[j] == 'o') coins[i]++;
        if (s[j] == 'x') traps[i]++;
      }
      maps[i][h] = s;
    }
  }
  string directions;
  string dir = "DRUL";
  vector<int> death(N);
  vector<int> sumGetCoins(N);  
  for (int t = 0; t < T; t++) {
    int nk = -1;
    double maxScore = -1;
    vector<int> notdeathids;
    for (int k = 0; k < 4; k++) {
      double nextScore = 0;
      for (int i = 0; i < N; i++) {
        if (death[i]) continue;
        else notdeathids.push_back(i);
        int nx = px[i] + dx[k];
        int ny = py[i] + dy[k];
        char nextCell = maps[i][ny][nx];
        if (nextCell == 'o') nextScore += 1;
        // if (nextCell == 'x') nextScore -= 0.01;
      }
      if (maxScore < nextScore) {
        maxScore = nextScore;
        nk = k;
      }
    }
    if (maxScore == 0) {
      if (notdeathids.size() > 0) {
        for (auto notdeathid : notdeathids) {
          // cerr << "Search" << endl;
          nk = bfs(px[notdeathid], py[notdeathid], maps[notdeathid]);
          // cerr << "Result : " << nk << endl; 
          if (nk != -1) break; 
        }
      } else {
        cerr << "All Dead" << endl;
        break;
      }
    }
    cerr << "Next Move : " << nk << endl;
    for (int i = 0; i < N; i++) {
      if (death[i]) continue;
      int nx = px[i] + dx[nk];
      int ny = py[i] + dy[nk];
      char nextCell = maps[i][ny][nx];
      if (nextCell == '#') {

      } else if (nextCell == 'o') {
        maps[i][ny][nx] = '.';
        sumGetCoins[i]++;
        px[i] = nx;
        py[i] = ny;
      } else if (nextCell == 'x') {
        death[i] = 1;
      } else if (nextCell == '.') {
        px[i] = nx;
        py[i] = ny;
      }
    }
    directions += dir[nk];
    cerr << t << " : "<< maxScore << endl;
  }

  vector<pair<int,int>> selected;
  for (int i = 0; i < N; i++) {
    selected.push_back(make_pair(-sumGetCoins[i],i));
  }
  sort(selected.begin(), selected.end());
  for (int i = 0; i < N; i++) {
    cerr << selected[i].first;
    if (i != N-1) cout << " ";
  }
  cerr << endl;

  for (int i = 0; i < K; i++) {
    cout << selected[i].second << " ";
  }cout << endl;
  cout << directions << endl;

  return 0;
}