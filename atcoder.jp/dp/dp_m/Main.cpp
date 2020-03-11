#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

long long dp[101][100001];
constexpr long long MOD = 1000000007;
int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for (int i = 0; i <= a[0]; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i < N; i++) {
    long long sum = 0;
    for (int k = 0; k <= K; k++) {
      sum = (sum + dp[i - 1][k]) % MOD;
      // cerr << k << " " << sum << endl;
      if (k - a[i] - 1 >= 0) sum = (sum + MOD - dp[i - 1][k - a[i] - 1]) % MOD;
      // for (int j = 0; j <= a[i]; j++) {
      //   if (k - j < 0) break;
      //   dp[i][k] += dp[i - 1][k - j];
      // }
      dp[i][k] = sum;
    }
  }
  // for (int i = 0; i < N; i++){
  //   for (int k = 0; k <= K; k++) {
  //     cerr << dp[i][k] << " ";
  //   }cerr << endl;
  // }

  cout << dp[N - 1][K] << endl;

  return 0;
}