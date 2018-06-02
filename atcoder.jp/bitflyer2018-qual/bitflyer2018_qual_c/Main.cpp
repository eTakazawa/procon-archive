#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, D;
  cin >> N >> D;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  vector<long long> dcount(N), upbound(N);
  for (int i = 0; i < N; i++) {
    int t = upper_bound(X.begin()+i, X.end(), X[i] + D) - X.begin();
    upbound[i] = t;
    dcount[i] = t - i - 1;
    cerr << dcount[i] << " ";
  }
  cerr << endl;
  for (int i = 1; i < N; i++) {
    dcount[i] += dcount[i - 1];
  }

  long long cnt = 0;
  for (int i = 0; i < N; i++) {
    if (i < upbound[i] - 1) {
      long long tmp = dcount[upbound[i] - 1] - dcount[i];
      long long n = upbound[i] - i - 1;
      cnt += tmp - (n * (n - 1) / 2);
    }
  }
  cout << cnt << endl;

  return 0;
}