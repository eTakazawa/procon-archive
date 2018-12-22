#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  bool odd = false;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] % 2 != 0) odd = true;
  }
  if (odd) cout << "first" << endl;
  else cout << "second" << endl;

  return 0;
}