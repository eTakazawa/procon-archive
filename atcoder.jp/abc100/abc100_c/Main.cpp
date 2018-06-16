#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  int ret = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    while (a[i] % 2 == 0) {
      // cerr << a[i] << endl;
      a[i] /= 2;
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}