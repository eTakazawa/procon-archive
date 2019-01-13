#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  string t = "keyence";
  if (s == t) {
    cout << "YES" << endl;
    return 0;
  }

  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      string ss;
      for (int k = 0; k < s.size(); k++) {
        if (i <= k && k <= i + j) continue;
        ss += s[k];
      }
      if (ss == t) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}