#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  vector<pair<int,int>> v;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    v.emplace_back(A[i] + B[i], i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  long long a = 0, b = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) a += A[v[i].second];
    else b += B[v[i].second];
  }

  cout << a - b << endl;
  return 0;
}