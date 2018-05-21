#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());

  vector<int> p(2);
  for (int i = 0; i < n; i++) {
    p[i % 2] += a[i];
  }
  cout << p[0] - p[1] << endl;
  return 0;
}