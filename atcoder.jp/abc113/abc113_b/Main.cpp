#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, t, a;
  cin >> n >> t >> a;
  double mindiff = 1e18;
  int mini = -1;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    double diff = abs(a - (t - h * 0.006));
    if (diff < mindiff) {
      mindiff = diff;
      mini = i;
    }
  }
  cout << mini + 1 << endl;
  return 0;
}