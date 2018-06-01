#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long n, m;
  cin >> n >> m;
  if (n < m) swap(n ,m);
  if (n > 1 && m > 1) {
    cout << (n - 2) * (m - 2) << endl; 
  } else if (n > 1) {
    cout << n - 2 << endl;
  } else {
    cout << 1 << endl;
  }

  return 0;
}