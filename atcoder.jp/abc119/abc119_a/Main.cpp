#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  if (s.substr(0, 7) <= "2019/04/30") {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }

  return 0;
}