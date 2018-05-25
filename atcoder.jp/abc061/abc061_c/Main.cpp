#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n), b(n);
  vector<pair<int,int>> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    p.emplace_back(a[i], b[i]);
  }

  sort(p.begin(), p.end());

  long long c = 0;
  for (int i = 0; i < n; i++) {
    long long aa = p[i].first;
    long long bb = p[i].second;
    if (k <= c + bb) {
      cout << aa << endl;
      return 0;
    }
    c += bb;
  }

  return 0;
}