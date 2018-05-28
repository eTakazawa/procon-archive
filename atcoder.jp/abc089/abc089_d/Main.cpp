#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W, D;
  cin >> H >> W >> D;
  vector<vector<int>> A(H, vector<int>(W));
  vector<pair<int,int>> mp(H * W + 1);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      mp[A[i][j]] = pair<int,int>(j, i);
    }
  }

  vector<int> cost(H * W + 1);
  for (int i = 1; i <= H * W - D; i++) {
    cost[i + D] = cost[i] + abs(mp[i].first - mp[i + D].first) + abs(mp[i].second - mp[i + D].second);
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    cout << cost[R] - cost[L] << endl;
  }

  return 0;
}