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
  static uint32_t y = 322436069;
  static uint32_t z = 523842629;
  static uint32_t w = 88675123; 
  uint32_t t;
 
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}

int H, W, D, K;
vector<int> r;
vector<int> c;
int getCost() {
  int cost = 0;
  for (int i = 1; i < D; i++) {
    cost += abs(r[i] - r[i-1]) + abs(c[i] - c[i-1]);
  }
  return cost;
}
int swapCost(int prevCost, int i, int j) {
  int diff1 = 0;
  int diff2 = 0;
  if (i) {
    diff1 += abs(r[i] - r[i-1]);
    diff1 += abs(c[i] - c[i-1]);
    diff2 += abs(r[j] - r[i-1]);
    diff2 += abs(c[j] - c[i-1]);
  }
  if (i < D-1) {
    diff1 += abs(r[i+1] - r[i]);
    diff1 += abs(c[i+1] - c[i]);
    diff2 += abs(r[i+1] - r[j]);
    diff2 += abs(c[i+1] - c[j]);
  }

  if (j) {
    diff1 += abs(r[j] - r[j-1]);
    diff1 += abs(c[j] - c[j-1]);
    diff2 += abs(r[i] - r[j-1]);
    diff2 += abs(c[i] - c[j-1]);
  }
  if (j < D-1) {
    diff1 += abs(r[j+1] - r[j]);
    diff1 += abs(c[j+1] - c[j]);
    diff2 += abs(r[j+1] - r[i]);
    diff2 += abs(c[j+1] - c[i]);
  }
  return prevCost - diff1 + diff2;
}
int swapCostRC(int prevCost, int i, int rj, int cj) {
  int diff1 = 0;
  int diff2 = 0;
  if (i) {
    diff1 += abs(r[i] - r[i-1]);
    diff1 += abs(c[i] - c[i-1]);
    diff2 += abs(rj - r[i-1]);
    diff2 += abs(cj - c[i-1]);
  }
  if (i < D-1) {
    diff1 += abs(r[i+1] - r[i]);
    diff1 += abs(c[i+1] - c[i]);
    diff2 += abs(r[i+1] - rj);
    diff2 += abs(c[i+1] - cj);
  }
  return prevCost - diff1 + diff2;
}
int main(void) {
  Timer timer;
  timer.start();
  cin >> H >> W >> D >> K;
  r.resize(D), c.resize(D);
  for (int i = 0; i < D; i++) {
    cin >> r[i] >> c[i];
  }

  int swapCount = 0, step = 0;
  int prevCost = getCost();
  long long currentTime = 0;
  int from = 0, to = 0;
  int bestScore = 1e9;
  while (timer.elapsedTime() < 3990) {
    step++;
    if (xor128() % 1000 < 100) {
      // 遷移 1
      int bestSwapTo = -1, from = xor128() % D;
      for (to = 0; to < D; to++) {
        if (from == to) continue;
        int nowCost = swapCost(prevCost, from, to);
        if (nowCost < bestScore) {
          bestScore = nowCost;
          bestSwapTo = to;
        }
      }
      if (bestSwapTo != -1) {
        prevCost = bestScore;
        cout << r[from] << " " << c[from] << " ";
        cout << r[bestSwapTo] << " " << c[bestSwapTo] << endl;
        swap(r[from], r[bestSwapTo]);
        swap(c[from], c[bestSwapTo]);
        swapCount++;
      }
    } else {
      // 遷移 2
      int bestRj = -1, bestCj = -1;
      from = xor128() % D;
      for (int rj = 0; rj < H; rj++) for (int cj = 0; cj < W; cj++) {
        int nowCost = swapCostRC(prevCost, from, rj, cj);
        if (nowCost < bestScore) {
          bestScore  = nowCost;
        }
      }
      if (bestRj != -1) {
        swapCount++;
        cout << r[from] << " " << c[from] << " ";
        cout << bestRj << " " << bestCj << endl;
        r[from] = bestRj;
        c[from] = bestCj;
      }
    }
    if (swapCount == K) break;
  }
  return 0;
}