#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  string s;
  cin >> n >> s;

  vector<int> e(n), w(n);
  int et = 0, wt = 0;
  for (int i = 0; i < n; i++) {
    if (s[n - i - 1] == 'E') e[n - i - 1] = ++et;
    else e[n - i - 1] = et;
    if (s[i] == 'W') w[i] = ++wt;
    else w[i] = wt;
  }

  for (int i = 0; i < n; i++) {
    cerr << w[i] << " ";
  }cerr << endl;
  for (int i = 0; i < n; i++) {
    cerr << e[i] << " ";
  }cerr << endl;

  int mincnt = 1e9;
  for (int i = 0; i < n; i++) {
    // cerr << e[i] + w[i] << endl;
    mincnt = min(mincnt, e[i] + w[i]);
  }
  cout << mincnt - 1 << endl;

  return 0;
}