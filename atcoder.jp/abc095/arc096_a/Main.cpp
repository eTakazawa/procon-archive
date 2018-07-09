#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  long long ret = 1e18;
  for (int i = 0; i <= 2*max(X, Y); i++) {
    long long remx = max(0LL, X - (i / 2));
    long long remy = max(0LL, Y - (i / 2));
    ret = min(ret, remx * A + remy * B + C * i);
  }
  cout << ret << endl;
  return 0;
}