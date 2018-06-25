#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  string s = to_string(n);
  int d = 0;
  for (int i = 0; i < s.size(); i++) {
    d += s[i] - '0';
  }
  if (n % d == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}