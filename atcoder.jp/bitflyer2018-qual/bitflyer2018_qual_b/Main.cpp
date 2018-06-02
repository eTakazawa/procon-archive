#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b, n;
  cin >> a >> b >> n;
  string x;
  cin >> x;
  for (int i = 0; i < n; i++) {
    if (x[i] == 'S') {
      if (a) a--;
    } else if (x[i] == 'C') {
      if (b) b--;
    } else {
      if (a > b) {
        if (a) a--;
      } else if (a < b) {
        if (b) b--;
      } else {
        if (a) a--;
      }
    }
  }
  cout << a << endl << b << endl;

  return 0;
}