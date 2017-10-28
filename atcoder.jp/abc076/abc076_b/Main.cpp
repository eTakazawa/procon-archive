#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,k;
  cin >> n >> k;
  int a = 1;
  for (int i = 0; i < n; i++) {
    if (a*2-a < k) a *= 2;
    else a += k;
  }
  cout << a << endl;
  return 0;
}