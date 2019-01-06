#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<long long> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  vector<long long> dp(N, 1e18);
  dp[0] = 0LL;
  for (int i = 0; i < N; i++) {
    for (int k = 1; k <= K; k++) {
      if (i + k >= N) break;
      dp[i + k] = min(dp[i + k], dp[i] + abs(h[i + k] - h[i]));
    }
  }
  cout << dp[N - 1] << endl;
  return 0;
}