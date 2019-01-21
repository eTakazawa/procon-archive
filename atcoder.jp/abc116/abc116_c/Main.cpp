#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  int ret = 0;
  for (int i = 0; i <= 100; i++) {
    int cnt = (h[0] > i) ? 1 : 0;
    for (int j = 1; j < N; j++) {
      if (h[j-1] <= i && h[j] > i) {
        cnt++;
      }
    }
    ret += cnt;
  }
  cout << ret << endl;
  return 0;
}