#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  int n = s.size();
  int ret = n;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) {
      if (i + 1 > n - i - 1) {
        ret = min(ret, i + 1);
      } else {
        ret = min(ret, n - i - 1);
      }
    } 
  }
  cout << ret << endl;
  return 0;
}