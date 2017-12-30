#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> c(N),s(N),f(N);
  for (int i = 0; i < N-1; i++) {
    cin >> c[i] >> s[i] >> f[i];
  }

  for (int i = 0; i < N-1; i++) {
    int t = 0;
    for (int j = i; j < N-1; j++) {
      if (t < s[j]) {
        t = s[j] + c[j];
      } else {
        if (t % f[j] == 0) {
          t += c[j];
        } else {
          t = ((t / f[j]) + 1) * f[j] + c[j];
        }
      }
    }
    cout << t << endl;
  }cout << 0 << endl;
  
  return 0;
}