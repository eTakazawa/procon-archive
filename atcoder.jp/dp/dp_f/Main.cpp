#include <iostream>
#include <vector>
#include <string>
using namespace std;

int memo[3002][3002];
int dir[3002][3002];
string s, t;
int dfs(int n, int m) {
  if (memo[n][m] != -1) return memo[n][m];
  int ret = 0;
  if (s[n] == t[m]) {
    ret = 1 + ((n > 0 && m > 0) ? dfs(n - 1, m - 1) : 0);
    dir[n][m] = 3;
  }
  if (n > 0) {
    int tmp = dfs(n - 1, m);
    if (tmp > ret) {
      ret = tmp;
      dir[n][m] = 2;
    }
  }
  if (m > 0) {
    int tmp = dfs(n, m - 1);
    if (tmp > ret) {
      ret = tmp;
      dir[n][m] = 1;
    }
  }
  return memo[n][m] = ret;
}

int main(void) {
  cin >> s >> t;
  s = "$" + s;
  t = "#" + t;
  
  int n = s.size();
  int m = t.size();
  memset(memo, -1, sizeof(memo));
  dfs(n - 1, m - 1);

  int now_n = n - 1, now_m = m - 1;

  if (dir[now_n][now_m] == 0) {
    cout << " " << endl;
    return 0;
  }

  string track;
  while (now_n > 0 && now_m > 0) {
    int d = dir[now_n][now_m];
    if (d == 0) break;
    if (d == 1) now_m--;
    if (d == 2) now_n--;
    if (d == 3) {
      track += s[now_n];
      now_n--, now_m--;
    }
  }
  reverse(track.begin(), track.end());
  cout << track << endl;

  return 0;
}