#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int H, W;
void dijkstra(int sx, int sy, int gx, int gy, vector<string>& s, vector<vector<int>>& dist) {
  const int inf = 1e9;
  dist = vector<vector<int>>(H, vector<int>(W, inf));
  dist[sy][sx] = 0;
  priority_queue<tuple<int,int,int>> pq;
  pq.emplace(0, sx, sy);
  while (!pq.empty()) {
    int d, x, y;
    tie(d, x, y) = pq.top();pq.pop();
    d = -d;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
      if (s[ny][nx] == '#') continue;
      int nd = d + 1;
      if (dist[ny][nx] > nd) {
        dist[ny][nx] = nd;
        pq.emplace(-nd, nx, ny);
      }
    }
  }
}

int main(void) {
  cin >> H >> W;
  vector<string> s(H);
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    cin >> s[i];
    for (int j = 0; j < W; j++) {
      if (s[i][j] == '.') cnt++;
    }
  }
  vector<vector<int>> dist;
  dijkstra(0, 0, W-1, H-1, s, dist);
  if (dist[H-1][W-1] == 1e9) cout << -1 << endl;
  else cout << cnt - (dist[H-1][W-1] + 1) << endl;

  return 0;
}