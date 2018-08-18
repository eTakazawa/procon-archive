#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  long long k;
  cin >> s >> k;
  int ix = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '1') break;
    else ix = i;
  }
  // cerr << ix << endl;
  if (ix == -1) {
    cout << s[0] << endl;
  } else if (k - 1 <= ix) {
    cout << 1 << endl;
  } else {
    cout << s[ix + 1] << endl;
  }

  return 0;
}