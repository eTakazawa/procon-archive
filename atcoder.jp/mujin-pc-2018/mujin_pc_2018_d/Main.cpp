#include <bits/stdc++.h>
using namespace std;

int rev(int x) {
  int ret = 0;
  while (x) {
    ret *= 10;
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int memo[1000][1000];

int main(void) {
  int N, M;
  cin >> N >> M;
  memset(memo, -1, sizeof(memo));
  int ret = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      bool ok = false;
      int x = i, y = j;
      if (memo[x][y] != -1) {
        ret += memo[x][y];
        continue;
      }
      set<pair<int,int>> st;
      while (x*y != 0) {
        if (memo[x][y] != -1) {
          ok = memo[x][y];
          break;
        }
        st.emplace(x, y);
        if (x < y) x = rev(x);
        else y = rev(y);

        if (x < y) y -= x;
        else x -= y;

        if (st.find(make_pair(x, y)) != st.end()) {
          ok = true;
          break;
        } 
      }
      if (ok) {
        for (const auto& p : st) {
          memo[p.first][p.second] = memo[p.second][p.first] = 1;
        }
        ret++;
      } else {
        memo[x][y] = memo[y][x] = 0;
        for (const auto& p : st) {
          memo[p.first][p.second] = memo[p.second][p.first] = 0;
        }
      }
    }
  }
  cout << ret << endl;
  return 0;
}