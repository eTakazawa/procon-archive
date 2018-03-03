#include <bits/stdc++.h>
using namespace std;
const int64_t CYCLES_PER_SEC = 2800000000;
 
struct Timer {
  int64_t start;
  Timer() { reset(); }
  void reset() { start = getCycle(); }
  void plus(double a) { start -= (a * CYCLES_PER_SEC); }
  inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
  inline int64_t getCycle() {
    uint32_t low, high;
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((int64_t)low) | ((int64_t)high << 32);
  }
};
unsigned int randxor(){
    static unsigned int x=123456789,y=362436009,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

const int N = 50;
int dist[N][N], used[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isOut(int x,int y) {
  return (x < 0 || y < 0 || x >= N || y >=N);
}
void calcMoveCost(vector<int>& warpX, vector<int>& warpY, vector<string>& A) {
  queue<pair<int,pair<int,int>>> que;
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dist[i][j] = 1e9;
  memset(used, 0, sizeof(used));
  for (int i = 0; i < warpX.size(); i++) {
    int y = warpY[i], x = warpX[i];
    que.emplace(-0, make_pair(y,x));
    dist[y][x] = 0;
  }
  
  int cnt = 0;
  while(!que.empty()) {
    int x,y,t;
    auto& p = que.front();que.pop();
    t = -p.first;
    y = p.second.first;
    x = p.second.second;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (isOut(nx,ny)) continue;
      if (!used[ny][nx]) {
        int cost = -1;
        if (A[ny][nx] == '.') cost = 10;
        else if (A[ny][nx] == '#') cost = 50;
        else if (A[ny][nx] == 'W') cost = 0;
        else if (A[ny][nx] == 'R') cost = 1;
        else if (A[ny][nx] == 'H') cost = 10;
        assert(cost != -1);
        if (dist[ny][nx] <= t + cost) continue;
        dist[ny][nx] = t + cost;
        que.push(make_pair(-dist[ny][nx], make_pair(ny, nx)));
      }
    }
    // if (t < 51)cerr << endl;
  }
}

struct State {
  int labour, money, score;
  int maxLabour;
  vector<int> warpX, warpY;
  vector<string> A;
  vector<vector<int>> tsukamo;
  State() {
    score = 0;
    maxLabour = labour = 100;
    money = 100;
    tsukamo = vector<vector<int>>(N, vector<int>(N));
    memset(dist, 0, sizeof(dist));
    input();
  }
  void showTsukamo() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%2d ", tsukamo[i][j]);
      }
      cout << endl;
    }
  }
  void showA() {
    for (int i = 0; i < N; i++) {
      cerr << A[i] << endl;
    }
  }
  void input() {
    A.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      for (int j = 0; j < N; j++) {
        if (A[i][j] == 'W') {
          warpX.push_back(j);
          warpY.push_back(i);
        }
      }
    }
  }
  void turnInit() {
    labour = maxLabour;
  }
  void growTsukamo() {
    vector<int> upx, upy;
    for (int i = 0; i< N; i++) {
      for (int j = 0; j < N; j++) {
        if (A[i][j] == 'H') {
          upx.push_back(j);upy.push_back(i);
        } else if (A[i][j] == '.') {
          for (int k = 0; k < 4; k++) {
            int ni = i + dy[k];
            int nj = j + dx[k];
            if (isOut(nj, ni)) continue;
            if (A[ni][nj] == 'H') {
              upx.push_back(j);upy.push_back(i);
              break;
            }
          }
        }
      }
    }
    for (int i = 0; i < upx.size(); i++) {
      int x = upx[i], y = upy[i];
      A[y][x] = 'H';
      tsukamo[y][x]++;
      if (tsukamo[y][x] == 100) {
        tsukamo[y][x] = 0;
        A[y][x] = '#';
      }
    }
  }
  bool road(int x1, int y1, int x2, int y2) {
    cout << "road " << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << endl;
    turn++;
    assert(x1 == x2 || y1 == y2);
    if (x1 == x2) {
      assert(y1 <= y2);
      int cost = (y2 - y1 + 1)*(y2 - y1 + 1);
      if (money < cost) return false;
      money -= cost;
      for (int y = y1; y <= y2; y++) {
        if (A[y][x1] == '.' || A[y][x1] == 'H') A[y][x1] = 'R';
      }
    } else {
      assert(x1 <= x2);
      int cost = (x2 - x1 + 1)*(x2 - x1 + 1);
      if (money < cost) return false;
      money -= cost;
      for (int x = x1; x <= x2; x++) {
        if (A[y1][x] == '.' || A[y1][x] == 'H') A[y1][x] = 'R';
      }
    }
    return true;
  }

  void plant(int x, int y) {
    cout << "plant " << x+1 << " " << y+1 << endl;
    turn++;
    if (A[y][x] == '.' || A[y][x] == 'H') {
      tsukamo[y][x]++;
      A[y][x] = 'H';
    }
  }
  int tryharvest(int x1, int y1, int x2, int y2) {
    // calcMoveCost(warpX, warpY, A);
    int obtain = 0;
    int laybour_ = labour;
    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++) {
        if (A[i][j] != 'H') continue;
        int lab = max(0, dist[i][j]  - 10);
        if (lab > laybour_) continue;
        laybour_ -= lab;
        obtain += tsukamo[i][j];
      }
    }
    return obtain;
  }
  void harvest(int x1, int y1, int x2, int y2) {
    cout << "harvest " << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << endl;
    turn++;
    assert(x1 <= x2 && y1 <= y2);
    calcMoveCost(warpX, warpY, A);
    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++) {
        if (A[i][j] != 'H') continue;
        int lab = max(0, dist[i][j]  - 10);
        if (lab > labour) continue;
        labour -= lab;
        money += tsukamo[i][j];
        score += tsukamo[i][j];
        tsukamo[i][j] = 0;
        A[i][j] = '.';
      }
    }
  }
  void work() {
    cout << "work" << endl;turn++;
    money++;
  }
  void destroy(int x1, int y1, int x2, int y2) {
    cout << "destroy " << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << endl;turn++;
    assert(x1 <= x2 && y1 <= y2);
    calcMoveCost(warpX, warpY, A);
    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++) {
        if (A[i][j] == 'W' || A[i][j] == '.') continue;
        int cost = dist[i][j];
        cerr << i << " " << j << " " << cost << endl;
        if (money < cost) continue;
        money -= cost;
        A[i][j] = '.';
        tsukamo[i][j] = 0;
      }
    }
  }
  void growup(int a) {
    cout << "growup " << a << endl;turn++;
    if (money < a * a) a = sqrt(money);
    maxLabour += a;
    money -= a * a;
  }
  bool warpgate(int x, int y) {
    cout << "warpgate " << x+1 << " " << y+1 << endl;turn++;
    if (money < 1000) return false;
    if (A[y][x] == '.' || A[y][x] == 'H' || A[y][x] == 'R') {
      A[y][x] = 'W';
      warpX.push_back(x);warpY.push_back(y);
      money -= 1000;
      return true;
    }
    return false;
  }

  pair<int,int> emptypoint(int x, int y,int& okX, int& okY) {
    int emY = emX = -10;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (isOut(nx,ny)) continue;
      okX = x;okY = y;
      if (A[ny][nx] == '.') {
        emX = nx;
        emY = ny;
        break;
      }
    }
    return pair<int,int>(emX,emY);
  }
  int turn, emX,emY;
  void solve() {
    turnInit();
    turn = 0;
    int x = warpX[0], y = warpY[0];
    int okY, okX;
    emY = emX = -1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (isOut(nx,ny)) continue;
      okX = x;okY = y;
      if (A[ny][nx] == '.') {
        emX = nx;
        emY = ny;
        break;
      }
    }

    // 消す
    if (emX == -1) {
      turnInit();
      destroy(okX,okY,okX,okY);
      emX = okX;emY = okY;
    }

    // 植える
    plant(emX, emY);
    growTsukamo();
    bool tate = false, yoko = false;
    int wx = warpX[0];
    int wy = warpY[0];
  
    while (turn < 1000) {
      turnInit();

      // 収穫
      calcMoveCost(warpX, warpY, A);
      int maxvalue = -1, md = -1;
      int maxcount = 0;
      int plantx = -1, planty;
      pair<int,int> p, wp(-1,-1);
      for (int i = 0; i < warpX.size(); i++) {
        int x = warpX[i], y = warpY[i];
        int tmp = 0;
        for (int xx = x - 10; xx < x + 10; xx++) for (int yy = y - 10; yy < y + 10; yy++) {
          int d = -1, prevValue = 0;
          if (isOut(xx,yy)) continue;
          if (maxcount < dist[yy][xx] && (A[yy][xx] == '.' || A[yy][xx] == 'H')) {
            maxcount = dist[yy][xx];
            wp = make_pair(xx, yy);
          }
          if (xx < x - 5 || xx > x + 5 || yy < y - 5 || yy > y + 5) continue;
          for (d = 1; d < 10; d++) {
            int value = tryharvest(max(0,xx-d), max(0,yy-d), min(xx+d,N-1), min(yy+d,N-1));
            if (prevValue > value) {
              d--;break;
            }
            prevValue = value;
          }
          tmp = max(prevValue ,tmp);
          if (maxvalue < prevValue) {
            maxvalue = prevValue;
            p = pair<int,int>(xx, yy);
            md = d;
          }
        }
        if (tmp == 0) {
          auto p__ = emptypoint(wx, wy, okX, okY);
          plantx = p__.first;
          planty = p__.second;
        }
      }
      
      bool aaa = false, bbb = true;
      if (plantx != -1) {
        if (plantx == -10) {
          destroy(okX, okY, okX, okY);
        } else {
          plant(plantx, planty);
        }
      }
      else if (money >= 10000 && !aaa){
        aaa = true;
        growup(sqrt(money));
      } else if (money  >= 20000){
        int ox = warpX[rand() % warpX.size()];
        int oy = warpY[rand() % warpY.size()];
        destroy(max(0,ox-10), max(0, oy-10), min(N-1,ox+10),min(N-1,oy+10) );
      } else if (wp.first != -1 && money >= 1000 && warpX.size() < 10) {
          int mx = wp.first, my = wp.second;
          // cerr << maxcount << endl;
          warpgate(mx, my);
      } else if (maxvalue > 30) {
        int hx = p.first, hy = p.second;
        harvest(max(0,hx-md), max(0,hy-md), min(hx+md,N-1), min(hy+md,N-1));
      }else if (money >= 100) {
        if (!tate) {
          road(max(0,wx), max(0,wy-5), min(wx,N-1), min(wy+5,N-1));
          tate = true;
        } else if (!yoko) {
          road(max(0,wx-5), max(0,wy), min(wx+5,N-1), min(wy,N-1));
          yoko = true;
        } else {
          growup(sqrt(money));
        }
      } else {
        work();
      }
      growTsukamo();
    }
  }
};

int main(void) {
  State state;
  state.solve();

// #if 0
  // for (int t = 0; t < 1000; t++) {
  //   state.turnInit();
    
  //   state.growTsukamo();
  // }
  // cout << state.score << endl;
// #endif
  return 0;
}
