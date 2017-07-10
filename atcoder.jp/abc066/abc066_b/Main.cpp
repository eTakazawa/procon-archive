#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  for(int i=s.size()-1;i>=0;i--){
    if(i%2==0){
      // cout << s.substr(0,i/2) << " " <<  s.substr(i/2,i/2) << endl;
      if(s.substr(0,i/2) == s.substr(i/2,i/2)){
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}