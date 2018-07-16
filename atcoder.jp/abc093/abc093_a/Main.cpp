#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if (s == "abc") cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}