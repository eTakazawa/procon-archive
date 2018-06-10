#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b;
  cin >> a >> b;

  int n = 0;
  for (int i = 1; i <= b-a; i++) {
    n += i;
  }
  cout << n - b << endl;
  return 0;
}