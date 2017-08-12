#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  string s = to_string(N);
  bool ok = true;
  for(int i=0;i<s.size();i++){
    if(s[i] != s[s.size()-i-1])ok = false;
  }
  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}