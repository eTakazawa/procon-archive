#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  int a = 9;
  vector<int> dr;
  dr.push_back(1);
  for (int i = 1;; i++) {
    dr.push_back(a);
    a *= 9;
    if (a > N) break;
  }
  a = 6;
  for (int i = 1;; i++) {
    dr.push_back(a);
    a *= 6;
    if (a > N) break;
  }

  sort(dr.begin(), dr.end());
  int dp[100001];
  for (int i = 0; i < 100001; i++) dp[i] = 1e9;

  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < dr.size(); j++) {
      if (i + dr[j] > N) continue;
      dp[i + dr[j]] = min(dp[i + dr[j]], dp[i] + 1);
    }
  }
  // reverse(dr.begin(), dr.end());
  // int cnt = 0;
  // while (N > 6) {
  //   cerr << N << endl;
  //   for (int i = 0; i < dr.size(); i++) {
  //     if (N >= dr[i]) {
  //       N -= dr[i];
  //       cerr << dr[i] << endl;
  //       cnt++;
  //       break;
  //     }
  //   }
  // }
  cout << dp[N] << endl;

  return 0;
}