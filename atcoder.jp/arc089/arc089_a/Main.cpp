#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int prev_x = 0, prev_y = 0, prev_t = 0;
  bool ok = true;
  for (int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    int diff = (t - prev_t) - (abs(prev_x - x) + abs(prev_y - y));
    // cerr << diff << endl;
    if (diff >= 0 && diff % 2 == 0) {
      prev_x = x;
      prev_y = y;
      prev_t = t;
    } else {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}