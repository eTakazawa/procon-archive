#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  string cols;
  vector<vector<int>> es(N);
  cin >> cols;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    es[a].push_back(b);
    es[b].push_back(a);
  }

  vector<int> blue(N), red(N);
  for (int i = 0; i < N; i++) {
    bool one_b = false, one_r = false;
    for (auto j : es[i]) {
      if (cols[j] == 'B') one_b = true;
      if (cols[j] == 'R') one_r = true;
    }
    blue[i] = one_b;
    red[i] = one_r;
  }
  if (K % 2 == 1) {
    for (int i = 0; i < N; i++) {
      if (blue[i]) cout << "First" << endl;
      else cout << "Second" << endl;
    }
  } else {
    for (int i = 0; i < N; i++) {
      bool lose = true;
      for (auto j : es[i]) {
        if (!red[j]) lose = false;
      }
      if (!lose) cout << "First" << endl;
      else cout << "Second" << endl;
    }
  }

  return 0;
}