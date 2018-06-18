#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int h, w;
  cin >> h >> w;
  vector<string> vs(h);
  for (int i = 0; i < h; i++) {
    cin >> vs[i];
  }

  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  bool ret = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (vs[i][j] != '#') continue;
      bool ok = false;
      for (int k = 0; k < 4; k++) {
        int ni = i + dy[k], nj = j + dx[k];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (vs[ni][nj] == '#') ok = true;
      }
      if (!ok) ret = false;
    }
  }
  cout << (ret ? "Yes" : "No") << endl;

  return 0;
}