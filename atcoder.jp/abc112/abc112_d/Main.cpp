#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  int maxx = M / N;
  for (int x = maxx; x >= 1; x--) {
    if ((M - x * N) % x == 0) {
      cout << x << endl;
      break;
    }
  }
  return 0;
}