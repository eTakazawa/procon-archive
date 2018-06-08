#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  int gp = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'p') gp--;
    else gp++;
  }
  cout << gp / 2<< endl;

  return 0;
}