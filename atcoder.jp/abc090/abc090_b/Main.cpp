#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = a; i <= b; i++) {
    string s = to_string(i);
    bool ok = true;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] != s[s.size() - 1 - j]) ok = false;
    }
    if (ok) cnt++;
  }
  cout << cnt << endl;

  return 0;
}