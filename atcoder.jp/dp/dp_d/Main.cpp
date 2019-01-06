#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }
  vector<long long> dp(W + 1);
  long long ret = 0;
  for (int i = 0; i < N; i++) {
    for (int wt = W; wt >= 0; wt--) {
      if (wt + w[i] > W) continue;
      dp[wt + w[i]] = max(dp[wt + w[i]], dp[wt] + v[i]);
      ret = max(dp[wt + w[i]], ret);
    }
  }
  cout << ret << endl;
  return 0;
}