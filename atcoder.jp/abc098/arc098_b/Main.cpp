#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ret = 0;
  int sum_ = 0, xor_ = 0;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n && (sum_ + a[r]) == (xor_ ^ a[r])) {
      sum_ += a[r];
      xor_ ^= a[r];
      r++;
    }
    ret += r - l;
    sum_ -= a[l];
    xor_ ^= a[l];
  }
  cout << ret << endl;
  return 0;
}