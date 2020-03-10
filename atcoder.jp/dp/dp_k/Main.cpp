#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int dp[100001] = {0};
  for (int i = 0; i <= K; i++) {
    if (dp[i] == 0) {
      for (int j = 0; j < N; j++) {
        int ni = i + a[j];
        if (ni > K) continue;
        dp[ni] = 1;
      }
    }
  }

  // for (int i = 0; i <= K; i++) {
  //   cout << dp[i];
  // }cout << endl;

  cout << (dp[K] == 1 ? "First" : "Second") << endl;

  return 0;
}