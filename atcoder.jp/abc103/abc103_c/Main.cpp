#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  long long l = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    l += a[i] - 1;
  }
  cout << l << endl;
  return 0;
}