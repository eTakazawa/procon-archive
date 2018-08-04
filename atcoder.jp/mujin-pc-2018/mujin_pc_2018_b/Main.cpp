#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int A;
  string s;
  cin >> A >> s;
  bool aru = false;
  for (int i = 0; i < s.size(); i++) {
    if (A == 0) aru = true;
    if (s[i] == '+') A++;
    else A--;
    if (A == 0) aru = true;
  }
  cout << (aru ? "Yes" : "No") << endl;

  return 0;
}