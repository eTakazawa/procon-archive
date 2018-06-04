#include <bits/stdc++.h>
using namespace std;

int N, Z, W;
vector<int> a;

int memo[2][2001][2001];
int dfs(int t, int n, int prev_n) {
  if (memo[t % 2][n][prev_n] != -1) return memo[t % 2][n][prev_n];
  int ret;
  if (t % 2 == 0) {
    ret = -1;
    for (int i = n; i < N; i++) {
      if (i + 1 != N) ret = max(dfs(t + 1, i + 1, i), ret);
      else ret = max(ret, abs(a[i] - a[prev_n]));
    }
  } else {
    ret = 1e9 + 1;
    for (int i = n; i < N; i++) {
      if (i + 1 != N) ret = min(dfs(t + 1, i + 1, i), ret);
      else ret = min(ret, abs(a[i] - a[prev_n]));
    }
  }
  return memo[t % 2][n][prev_n] = ret;
}

int main(void) {
  cin >> N >> Z >> W;
  memset(memo, -1, sizeof(memo));
  a = vector<int>(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  a[N] = W;
  cout << dfs(0, 0, N) << endl;
  return 0;
}
