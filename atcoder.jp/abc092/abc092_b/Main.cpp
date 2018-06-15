#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, D, X;
  cin >> N >> D >> X;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    for (int j = 0;; j++) {
      if (1 + a * j <= D) {
        X++;
      } else {
        break;
      }
    }
  }
  cout << X << endl;
  return 0;
}