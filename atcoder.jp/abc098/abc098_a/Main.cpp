#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b;
  cin >> a >> b;
  int d = a + b, e = a - b, f = a * b;
  cout << max({d,e,f}) << endl;
  return 0;
}