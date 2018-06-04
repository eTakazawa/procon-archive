#include <bits/stdc++.h>
using namespace std;

int main(void) {
  char x, y;
  cin >> x >> y;
  if (x == y) cout << "=" << endl;
  else {
    cout << (x > y ? ">" : "<") << endl;
  }
  return 0;
}