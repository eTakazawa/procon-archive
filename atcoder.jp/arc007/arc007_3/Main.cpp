#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string c;
  cin >> c;

  int n = (int)c.size();
  int ret = 1e9;
  for (int rot = 0; rot < n; rot++) {
    for (int i = 0; i < (1<<n); i++) { // ビット全探索
      vector<int> on(n);
      for (int j = 0; j < n; j++) { // 何ビット目（j個目テレビを使うか）
        if ((i>>j) & 1) {
          for (int k = 0; k < n; k++) { // j個目のテレビの時間帯
            if (c[k] == 'o') on[(k + j) % n] = 1; // j個目なので,j分ずれた所
          }
        }
      }
      int sum = accumulate(on.begin(), on.end(), 0); // onが全部1なら
      if (sum == n) {
        ret = min(ret, __builtin_popcount(i));
      }
    }
    c = c.substr(1) + c[0]; // 一番前の文字を末尾につける
  }
  cout << ret << endl;
  return 0;
}