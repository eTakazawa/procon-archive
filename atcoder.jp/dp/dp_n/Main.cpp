#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<vector<long long>> dp(N, vector<long long>(N + 1));
  vector<long long> acc(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> acc[i + 1];
  }
  for (int i = 1; i <= N; i++) {
    acc[i] += acc[i - 1];
  }

  for (int width = 2; width <= N; width++) {
    for (int i = 0; i < N - width + 1; i++) {
      long long min_sum = 1e18;
      for (int j = 1; j < width; j++) {
        long long sum = dp[i][i + j] + dp[i + j][i + width];
        sum += (acc[i + j] - acc[i]) + (acc[i + width] - acc[i + j]);
        min_sum = min(min_sum, sum);
        // printf("\n");
        // printf("(%d,%d) = %d + ", i, i + j, dp[i][i + j]);
        // printf("(%d,%d) = %d + ", i + j, i + width, dp[i + j][i + width]);
        // printf("%d-%d+%d-%d\n", acc[i + j], acc[i], acc[i + width], acc[i + j]);
      }
      dp[i][i + width] = min_sum;
    }
  }
  cout << dp[0][N] << endl;

  return 0;
}