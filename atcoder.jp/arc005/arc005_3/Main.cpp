#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W;
  vector<string> grid;
  cin >> H >> W;
  string s;

  int sx,sy,gx,gy;
  for (int i = 0; i < H; i++) {
    cin >> s;
    grid.push_back(s);
    for (int j = 0; j < s.size(); j++) {
      if (grid[i][j] == 's') {
        sx = j;
        sy = i;
      } else if (grid[i][j] == 'g') {
        gx = j;
        gy = i;
      }
    }
  }

  int dx[] = {0, 1, 0 ,-1};
  int dy[] = {1, 0, -1, 0};

  int visited[501][501];
  memset(visited, 0, sizeof(visited));

  queue<pair<int,int>> que;
  que.emplace(sy, sx);

  bool ok = false;
  for (int t = 0; t < 3; t++) {
    set<pair<int,int>> walls;
    memset(visited, 0, sizeof(visited));
    while (!que.empty()) {
      int y, x;
      tie(y, x) = que.front(); que.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
        if (visited[ny][nx]) continue;
        if (grid[ny][nx] == 'g') {
          ok = true;
          break;
        }
        if (grid[ny][nx] == '#') walls.emplace(ny, nx);
        if (grid[ny][nx] == '.') {
          visited[ny][nx] = 1;
          que.emplace(ny, nx);
        }
      }
    }
    for (const auto& wall : walls) {
      que.emplace(wall);
    }
  }

  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}