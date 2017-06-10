#include <bits/stdc++.h>
using namespace std;

int main(void){
  int r,g,b;
  cin >> r >> g >> b;
  int t = r*100+g*10+b;
  cout << (t%4==0 ? "YES" : "NO") << endl;

  return 0;
}