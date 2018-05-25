#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    x[--a]++;
    x[--b]++;
  }
  for (int i = 0; i < n; i++) {
    cout << x[i] << endl;
  }

  return 0;
}