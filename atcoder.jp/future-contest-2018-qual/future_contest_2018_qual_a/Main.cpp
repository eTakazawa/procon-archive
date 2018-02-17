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
unsigned int randxor(){
    static unsigned int x=123456789,y=362436009,z=521288629,w=88635123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

const int N = 100;
const int T = 1000;
int A[N][N], B[N][N], C[N][N];

long long getcost() {
  long long cost = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cost += abs(A[i][j] - B[i][j]);
    }
  }
  return cost;
}
long long setMount(int x, int y, int h) {
  int minY = max(0,y-h), maxY = min(N, y+h);
  int minX = max(0,x-h), maxX = min(N, x+h);
  long long diff = 0;
  for (int i = minY; i < maxY; i++) {
    for (int j = minX; j < maxX; j++) {
      int val = max(0, h - abs(x - j) - abs(y - i));
      diff += abs(A[i][j] - B[i][j]);
      B[i][j] += val;
      diff -= abs(A[i][j] - B[i][j]);
    }
  }
  return diff;
}
long long undoMount(int x, int y, int h) {
  int minY = max(0,y-h), maxY = min(N, y+h);
  int minX = max(0,x-h), maxX = min(N, x+h);
  long long diff = 0;
  for (int i = minY; i < maxY; i++) {
    for (int j = minX; j < maxX; j++) {
      int val = max(0, h - abs(x - j) - abs(y - i));
      diff += abs(A[i][j] - B[i][j]);
      B[i][j] -= val;
      diff -= abs(A[i][j] - B[i][j]);
    }
  }
  return diff;
}
long long changeHeight(int x, int y, int ph, int h) {
  long long diff = 0;
  if (ph < h) {
    int minY = max(0,y-h), maxY = min(N, y+h);
    int minX = max(0,x-h), maxX = min(N, x+h);
    for (int i = minY; i < maxY; i++) {
      for (int j = minX; j < maxX; j++) {
        int c = -abs(x - j) - abs(y - i);
        int pval = max(0, ph + c);
        int val = max(0, h + c);
        diff += abs(A[i][j] - B[i][j]);
        B[i][j] += val - pval;
        diff -= abs(A[i][j] - B[i][j]);
      }
    }
  } else {
    swap(ph, h);
    int minY = max(0,y-h), maxY = min(N, y+h);
    int minX = max(0,x-h), maxX = min(N, x+h);
    for (int i = minY; i < maxY; i++) {
      for (int j = minX; j < maxX; j++) {
        int c = -abs(x - j) - abs(y - i);
        int pval = max(0, ph + c);
        int val = max(0, h + c);
        diff += abs(A[i][j] - B[i][j]);
        B[i][j] += -val + pval;
        diff -= abs(A[i][j] - B[i][j]);
      }
    }
  }
  return diff;
}

int main(void) {
  Timer timer;
  timer.start();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  
  vector<int> ax,ay,ah;
  int t = 0;
  long long prevCost = getcost();
  while (t < T) {
    int x = randxor() % N, y = randxor() % N, h = randxor() % N + 1;
    int nowCost = prevCost - setMount(x, y, h);
    if (prevCost > nowCost) {
      prevCost = nowCost;
      ax.push_back(x);ay.push_back(y);ah.push_back(h);
      t++;
    } else undoMount(x, y, h);
  }
#ifdef DEBUG
  long long beforeGreedy = timer.elapsedTime();
#endif

  int Q = ax.size();
  int tryCount = 0;
  prevCost = getcost();
  while (timer.elapsedTime() < 5996) {
    // １つをランダムに変更
    {
      int i = randxor() % Q;
      int px = ax[i], py = ay[i], ph = ah[i];
      long long diff = undoMount(px, py, ph);

      int x = randxor() % N, y = randxor() % N, h = randxor() % N + 1;
      long long diff2 = setMount(x, y, h);
      long long nowCost = prevCost - diff - diff2;
      if (prevCost > nowCost) {
        prevCost = nowCost;
        ax[i] = x; ay[i] = y; ah[i] = h;
      } else {
        undoMount(x, y, h);
        setMount(px, py, ph);
      }
    }
    // 1つの高さを変更
    {
      int i = randxor() % Q;
      int px = ax[i], py = ay[i], ph = ah[i];
      int h = ph + (A[py][px] > B[py][px] ? 1 : -1);
      if (h < 1 || h > 100) continue;
      
      long long diff = changeHeight(px, py, ph, h);
      long long nowCost = prevCost - diff;
      if (prevCost > nowCost) {
        prevCost = nowCost;
        ah[i] = h;
      } else {
        changeHeight(px, py, h, ph);
      }
    }

#ifdef COUNT
    tryCount++;
#endif
  }
#ifdef COUNT
  cerr << "tryCount : " << tryCount << endl;
#endif
#ifdef DEBUG
  cerr << "before swap : " << beforeGreedy << endl;
  cerr << 200000000LL - getcost() << endl;
#endif
#ifndef DEBUG
  cout << ax.size() << endl;
  for (int i = 0; i < ax.size(); i++) {
    cout << ax[i] << " " << ay[i] << " " << ah[i] << endl;
  }
#endif
  return 0;
}
