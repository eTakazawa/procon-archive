#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long X, Y;
  cin >> X >> Y;

  long long now = X;
  int cnt = 0;
  while (now <= Y) {
    cnt++;
    now *= 2;
  }
  cout << cnt << endl;
  return 0;
}