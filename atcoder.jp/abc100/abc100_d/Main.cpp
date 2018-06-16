#include <bits/stdc++.h>
using namespace std;

int N, M;
const long long inf = (long long)(-1e18);
vector<vector<long long>> vadd;
long long memo[1001][1001][8];
long long dfs(int n, int m, const int& j) {
  if (memo[n][m][j] != inf) return memo[n][m][j];
  if (n == N && m < M) return memo[n][m][j] = 2*inf;
  if (m == M) return memo[n][m][j] = 0;
  if (m > M || n > N) return memo[n][m][j] = 2*inf;
  return memo[n][m][j] = max(dfs(n + 1, m + 1, j) + vadd[j][n], dfs(n + 1, m, j));
}

int main(void) {
  cin >> N >> M;
  vadd = vector<vector<long long>>(8, vector<long long>(N));
  vector<vector<long long>> v(3, vector<long long>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v[j][i];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 3; k++) {
        if ((j >> k) & 1) {
          vadd[j][i] += v[k][i];
        } else {
          vadd[j][i] -= v[k][i];
        }
      }
    }
  }

  for (int i = 0; i < 1001; i++) for (int j = 0; j < 1001; j++) {
    for (int k = 0; k < 8; k++) {
      memo[i][j][k] = inf;
    }
  }

  long long ret = 0;
  for (int j = 0; j < 8; j++) {
    ret = max(ret, dfs(0, 0, j));
  }
  cout << ret << endl;
  return 0;
}