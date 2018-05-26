#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  string s;
  cin >> n >> s;
  int maxcnt = 0;
  for (int i = 0; i < n; i++) {
    vector<int> a(26), b(26);
    for (int j = 0; j < n; j++) {
      if (j < i) {
        a[s[j] - 'a']++;
      } else {
        b[s[j] - 'a']++;
      }
    }
    int cnt = 0;
    for (int j = 0; j < 26; j++) {
      if (a[j] && b[j]) cnt++;
    }
    maxcnt = max(maxcnt, cnt);
  }
  cout << maxcnt << endl;
  return 0;
}