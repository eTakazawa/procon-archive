#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> T(N), A(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i] >> A[i];
  }

  long long t = 1LL, a = 1LL;
  for (int i = 0; i < N; i++) {
    if (T[i] >= t && A[i] >= a) {
      t = T[i];
      a = A[i];
    } else {
      long long b = max(ceil((long double)t / T[i]), ceil((long double)a / A[i]));
      t = T[i] * b;
      a = A[i] * b;
    }
  }
  cout << t + a << endl;
  return 0;
}
