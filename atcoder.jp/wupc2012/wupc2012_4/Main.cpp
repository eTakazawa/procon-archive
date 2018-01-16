#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<vector<int>> a(N,vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i + 1; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> dp(N,vector<int>(N));
  dp[0][0] = a[0][0];
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
      dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);
    }
  }

  int ret = 0;
  for (int i = 0; i < N; i++) {
    ret = max(ret, dp[N-1][i]);
  }
  cout << ret << endl;
  return 0;
}
