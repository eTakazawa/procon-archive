#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  int L, R;
  int maxL = 0, minR = N + 1;
  for (int i = 0; i < M; i++) {
    cin >> L >> R;
    maxL = max(L, maxL);
    minR = min(R, minR);
  }
  if (minR - maxL >= 0)
    cout << minR - maxL + 1 << endl;
  else
    cout << 0 << endl;

  return 0;
}