#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long N, K;
  cin >> N >> K;

  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  long long ret = 0;
  for (long long b = 1; b <= N; b++) {
    ret += (N / b) * max(0LL, (b - K)) + max(0LL, (N % b - K + 1LL));
  }
  cout << ret << endl;
  return 0;
}