#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,c;
  cin >> a >> b >> c;
  cout << min(a+b,min(a+c,b+c)) << endl;
  return 0;
}