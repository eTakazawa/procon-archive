#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> s(M);
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int ss;cin >> ss;ss--;
      s[i].push_back(ss);
    }
  }

  vector<int> p(M);
  for (int i = 0; i < M; i++) {
    cin >> p[i];
  }

  int ret = 0;
  for (int i = 0; i < (1 << N); i++) {
    int lighton = 0;
    for (int j = 0; j < M; j++) {
      int on = 0;
      for (int ss : s[j]) {
        if (i & (1 << ss)) on++;
      }
      if (on % 2 == p[j]) lighton++;
    }
    if (lighton == M) ret++;
  }
  cout << ret << endl;
  return 0;
}