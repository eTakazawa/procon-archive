#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<vector<int>> h(N, vector<int>(3));
  for (int i = 0; i < N; i++) {
    cin >> h[i][0] >> h[i][1] >> h[i][2];
  }

  vector<vector<long long>> dp(100001, vector<long long>(3, -1));
  dp[0][0] = dp[0][1] = dp[0][2] = 0LL;
  long long ret = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      if (dp[i][j] == -1) continue;
      for (int k = 0; k < 3; k++) {
        if (j == k) continue;
        dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + h[i][k]);
        ret = max(dp[i + 1][k], ret);
      }
    }
  }
  cout << ret << endl;

  return 0;
}