#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N; 
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  const int MOD = 1000000007;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum = (sum + A[i]) % MOD;
  }

  long long ret = 0;
  for (int i = 0; i < N - 1; i++) {
    sum = (sum + MOD - A[i]) % MOD;
    ret = (ret + (A[i] * sum % MOD)) % MOD;
  }
  cout << ret << endl;

  return 0;
}