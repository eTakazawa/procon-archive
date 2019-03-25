#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  int ret = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j <= s.size(); j++) {
      int cnt = 0;
      for (int k = i; k < j; k++) {
        if (s[k] == 'A' || s[k] == 'G' || s[k] == 'T' || s[k] == 'C') {
          cnt++;
        } else break;
      }
      ret = max(ret, cnt);
    }
  }
  cout << ret << endl;
  return 0;
}