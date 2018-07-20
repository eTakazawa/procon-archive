#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  int dist = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    dist += min(abs(x - K), abs(x - 0)) * 2;
  }
  cout << dist << endl;
  return 0;
}