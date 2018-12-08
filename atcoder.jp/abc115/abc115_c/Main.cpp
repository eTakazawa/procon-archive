#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  int ret = 2e9;
  for (int i = K - 1; i < N; i++) {
    ret = min(ret, h[i] - h[i - K + 1]);
  }
  cout << ret << endl;

  return 0;
}