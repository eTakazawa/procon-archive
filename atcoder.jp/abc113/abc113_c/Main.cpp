#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> years(N + 1);
  vector<int> vp, vy;
  for (int i = 0; i < M; i++) {
    int p, y;
    cin >> p >> y;
    vp.push_back(p);
    vy.push_back(y);
    years[p].push_back(y);
  }
  for (int i = 0; i <= N; i++) {
    if (!years[i].empty()) {
      sort(years[i].begin(), years[i].end());
    }
  }

  for (int i = 0; i < M; i++) {
    auto it = lower_bound(years[vp[i]].begin(), years[vp[i]].end(), vy[i])
              - years[vp[i]].begin();
    printf("%06d%06d\n", vp[i], it + 1);
  }
  return 0;
}