#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;

  cout << (int)(pow(K - 1, N - 1) * K) << endl;
  return 0;
}