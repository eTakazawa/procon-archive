#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b, c;
  int k;
  cin >> a >> b >> c >> k;
  if (b < c) swap(b, c);
  if (a < b) swap(a, b);

  cout << a * (1 << k) + b + c << endl;
  return 0;
}