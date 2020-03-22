#include <bits/stdc++.h>
using namespace std;

int dp[22][(1 << 22)];
int main(void) {
  int N;
  cin >> N;
  int a[22][22];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int used = 0; used < (1 << N); used++) {
      if (dp[i][used] == 0) continue;
      for (int nx = 0; nx < N; nx++) {
        if ((used >> nx) & 1) continue;
        if (!a[i][nx]) continue;
        dp[i + 1][used | (1 << nx)] += dp[i][used];
        dp[i + 1][used | (1 << nx)] %= 1000000007;
      }
    }
  }
  
  cout << dp[N][(1 << N) - 1] << endl;  

  return 0;
}