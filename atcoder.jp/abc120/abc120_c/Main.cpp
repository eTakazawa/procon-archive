#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  int zero = 0, one = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') zero++;
    if (s[i] == '1') one++;
  }
  cout << min(zero, one) * 2 << endl;

  return 0;
}