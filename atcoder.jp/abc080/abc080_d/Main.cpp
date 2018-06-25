#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, C;
  cin >> N >> C;
  vector<int> s(N), t(N), c(N);
  vector<vector<int>> used(C, vector<int>(100001));

  for (int i = 0; i < N; i++) {
    cin >> s[i] >> t[i] >> c[i];
    c[i]--;
    for (int j = s[i]; j <= t[i]; j++) {
      used[c[i]][j] = 1;
    }
  }
    
  int ret = 0;
  for (int i = 0; i < 100001; i++) {
    int cnt = 0;
    for (int j = 0; j < C; j++) {
      cnt += used[j][i];
    }
    ret = max(cnt, ret);
  }
  cout << ret << endl;
  
  return 0;
}