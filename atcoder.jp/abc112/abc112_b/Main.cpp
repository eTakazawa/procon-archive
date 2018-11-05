#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, T;
  cin >> N >> T;
  int minc = 1e9;
  for (int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;
    if (t <= T) minc = min(minc, c);
  }
  cout << (minc == 1e9 ? "TLE" : to_string(minc)) << endl;
  return 0;
}