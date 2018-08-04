#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (t  ==
        s.substr(i, s.size() - i) + s.substr(0, i)) {
      cout << "Yes" << endl;
    return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}