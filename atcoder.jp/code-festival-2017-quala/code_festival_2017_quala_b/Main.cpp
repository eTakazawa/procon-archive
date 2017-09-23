#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N,M,K;
  cin >> N >> M >> K;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      int num = (M - j) * (N - i) + j * i;
      if (num == K) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}