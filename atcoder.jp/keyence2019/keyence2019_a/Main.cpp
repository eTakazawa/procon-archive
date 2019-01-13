#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string a, b, c, d;
  cin >> a >> b >> c >> d;
  string s = a + b + c + d;
  sort(s.begin(), s.end());
  if (s == "1479") cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}