#include <bits/stdc++.h>
using namespace std;

// dp[何個目のサイコロ][約数の2の数][約数の3の数][約数の5の数]
#define N2 65
#define N3 50
#define N5 30

double dp[110][N2][N3][N5];
int num[6];

int main(void) {
  int N;
  long long D;
  cin >> N >> D;

  while (D % 2 == 0) { D /= 2; num[2]++; }
  while (D % 3 == 0) { D /= 3; num[3]++; }
  while (D % 5 == 0) { D /= 5; num[5]++; }
  if (D != 1) { cout << 0.0 << endl; return 0; }

  dp[0][0][0][0] = 1.0;
  for (int t = 0; t < N; t++) {
    for (int i = 0; i < N2-2; i++) {
      for (int j = 0; j < N3-1; j++) {
        for (int k = 0; k < N5-1; k++) {
          dp[t+1][i][j][k] += dp[t][i][j][k] / 6.0;
          dp[t+1][min(num[2],i+1)][j][k] += dp[t][i][j][k] / 6.0;
          dp[t+1][i][min(num[3],j+1)][k] += dp[t][i][j][k] / 6.0;
          dp[t+1][min(num[2],i+2)][j][k] += dp[t][i][j][k] / 6.0;
          dp[t+1][i][j][min(num[5],k+1)] += dp[t][i][j][k] / 6.0;
          dp[t+1][min(num[2],i+1)][min(num[3],j+1)][k] += dp[t][i][j][k] / 6.0;
        }
      }
    }
  }

  double ret = 0.0;
  for (int i = num[2]; i < N2; i++) {
    for (int j = num[3]; j < N3; j++) {
      for (int k = num[5]; k < N5; k++) {
        ret += dp[N][i][j][k];
      }
    }
  }
  cout << fixed << setprecision(12) << ret << endl;
  return 0;
}
