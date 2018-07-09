#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, X;
  cin >> N >> X;
  int minm = 1e8;
  for (int i = 0; i < N; i++) {
    int m;
    cin >> m;
    X -= m;
    minm = min(minm, m);
  }
  cout << N + X / minm << endl;
  return 0;
}