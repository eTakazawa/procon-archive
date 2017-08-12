#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int cnt = 0;
  for(int i=0;i<=100;i++){
    if(a <= i && i < b && c <= i && i < d)
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}