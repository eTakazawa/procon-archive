#include <iostream>
#include <vector>
using namespace std;

long long dp[1001][1001];
int main(void) {
  int N, M;
  cin >> N >> M;
  vector<string> a(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  dp[0][0] = 1;
  long long MOD = 1000000007;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (i < N - 1 && a[i + 1][j] == '.') dp[i + 1][j] += dp[i][j];
      if (j < M - 1 && a[i][j + 1] == '.') dp[i][j + 1] += dp[i][j];

      dp[i + 1][j] %= MOD;
      dp[i][j + 1] %= MOD;
    }
  }
  cout << dp[N - 1][M - 1] << endl;

  return 0;
}