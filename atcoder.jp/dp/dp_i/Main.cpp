#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double dp[3001][3001];
int main(void) {
  int N;
  cin >> N;
  vector<double> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  dp[0][0] = 1.0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
      double prob = p[i];
      dp[i + 1][j + 1] += dp[i][j] * prob;
      dp[i + 1][j]     += dp[i][j] * (1 - prob);
    }
  }

  double ret = 0;
  for (int i = N / 2 + 1; i <= N; i++) {
    ret += dp[N][i];
    // cerr << i << " : " << dp[N][i] << endl;
  }
  cout << fixed << setprecision(10) << ret << endl;

  return 0;
}