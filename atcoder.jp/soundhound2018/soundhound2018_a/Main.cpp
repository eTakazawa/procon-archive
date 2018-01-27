#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string x,y;
  cin >> x >> y;
  string s;
  s += x[0];
  s += y[0];
  if (s == "SH") cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}