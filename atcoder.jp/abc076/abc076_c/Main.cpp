#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s,t;
  cin >> s >> t;

  string need(t.size(),'?');
  bool ok = false;
  for (int i = s.size()-1; i >= 0; i--) {
    if (i + t.size()-1 < s.size()) {
      int id = i;
      for (int j = 0; j < t.size(); j++) {
        if (!(s[i+j] == '?' || s[i+j] == t[j])) {
          id = -1;
          break;
        }
      }
      if (id != -1) {
        for (int j = 0; j < t.size(); j++) {
          s[id+j] = t[j];
        }
        ok = true;
        break;
      }
    }
  }
  if (ok) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '?') s[i] = 'a';
    }
    cout << s << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }

  return 0;
}