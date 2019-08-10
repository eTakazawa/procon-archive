#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  map<int, long long> amari;
  long long ret = 0, sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];
    ret += amari[sum % M];
    if (sum % M == 0) ret++;
    amari[sum % M]++;
    // cerr << i << " " << ret << " " << sum << " " << sum % M << endl;
  }

  cout << ret << endl;
  return 0;
}