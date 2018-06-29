#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, T;
  cin >> N >> T;
  vector<int> t(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  long long now = 0;
  for (int i = 0; i < N - 1; i++) {
    if (t[i] + T > t[i+1]) {
      now += t[i+1] - t[i];
    } else {
      now += T;
    }
  }
  cout << now + T << endl;

  return 0;
}