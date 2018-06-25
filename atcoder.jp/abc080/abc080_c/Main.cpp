#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<vector<int>> f(N, vector<int>(10));
  vector<vector<int>> p(N, vector<int>(11));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> f[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> p[i][j];
    }
  }

  long long ret = -1e18;
  for (int i = 0; i < (1 << 10); i++) {
    if (__builtin_popcount(i) == 0) continue;
    vector<int> c(N);
    for (int j = 0; j < 10; j++) {
      if ((i >> j) & 1) {
        for (int k = 0; k < N; k++) {
          if (f[k][j]) c[k]++;
        }
      }
    }
    long long sum = 0;
    for (int j = 0; j < N; j++) {
      sum += p[j][c[j]];
    }
    ret = max(ret, sum);
  }
  cout << ret << endl;
  return 0;
}