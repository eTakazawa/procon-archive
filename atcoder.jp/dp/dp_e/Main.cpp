#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }
  vector<long long> dp(100 * 1000 + 1, 1e18);
  dp[0] = 0;
  long long ret = 0;
  for (int i = 0; i < N; i++) {
    for (int vl = 100 * 1000; vl >= 0; vl--) {
      if (dp[vl] + w[i] > W) continue;
      dp[vl + v[i]] = min(dp[vl + v[i]], dp[vl] + w[i]);
      ret = max((long long)(vl + v[i]), ret);
    }
  }
  cout << ret << endl;
  return 0;
}