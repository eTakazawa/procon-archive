#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  vector<long long> dp(N, 1e18);
  dp[0] = 0LL;
  for (int i = 0; i < N; i++) {
    if (i + 1 < N)
      dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
    if (i + 2 < N)
      dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
  }
  cout << dp[N - 1] << endl;
  return 0;
}