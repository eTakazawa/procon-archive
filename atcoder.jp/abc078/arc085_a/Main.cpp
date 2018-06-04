#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;

  int iter_t = 100 * (N - M) + 1900 * M;
  cout << iter_t * (1 << M) << endl;

  return 0;
}