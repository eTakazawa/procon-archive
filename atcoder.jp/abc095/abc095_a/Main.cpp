#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'o') cnt++;
  }
  cout << 700 + cnt * 100 << endl;
  return 0;
}