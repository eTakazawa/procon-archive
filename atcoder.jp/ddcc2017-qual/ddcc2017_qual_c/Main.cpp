#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N,C;
  cin >> N >> C;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  sort(L.begin(),L.end());
  reverse(L.begin(),L.end());

  int a = N - 1;
  int ret = 0;
  for (int i = 0; i < N; i++) {
    // cerr << a << " " << i << endl;
    if (i == a) {
      ret++;
      break;
    }
    if (a > i && L[a] + L[i] + 1 <= C) {
      ret++;
      a--;
      if (i == a) break;
    } else {
      ret++;
    }

  }
  cout << ret << endl;
  return 0;
}