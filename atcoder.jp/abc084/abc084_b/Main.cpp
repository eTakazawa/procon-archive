#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string a, b;
  string s;
  cin >> a >> b >> s;
  regex re("(\\d{" + a + "}-\\d{" + b + "})");
  if (regex_match(s, re)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
  
  return 0;
}