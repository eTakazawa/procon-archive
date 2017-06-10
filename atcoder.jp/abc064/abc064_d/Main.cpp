#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n;
  string s;
  cin >> n >> s;

  int r=0;
  for(int i=s.size()-1;i>=0;i--){
    if(s[i]==')') r++;
    else{
      r--;
      if(r < 0) r = 0;
    }
  }
  cerr << r << endl;
  s = string(r,'(') + s;
  cerr << s << endl;

  int l = 0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='(') l++;
    else{
      l--;
      if(l < 0) l = 0;
    }
  }
  cerr << l << endl;
  cout << s + string(l,')') << endl;

  return 0;
}