#include <bits/stdc++.h>
using namespace std;


// 0 なら赤色に、 
// 1 なら青色に、 
// 2 なら緑色に、 
// 3 なら黄色

// 100, 500
int N, M;

//UDLR
enum {
  UP = 0,
  DOWN,
  LEFT,
  RIGHT,
};
struct Action {
  int r, c, dir;
  Action() : r(-1), c(-1), dir(-1) {}
};

char dirchar[] = {'U', 'D', 'L', 'R'};
int dc[] = {0, 0, -1, 1};
int dr[] = {-1, 1, 0, 0};
void draw(int r, int c, int color, int dir, vector<vector<int>>& g, Action& act) {

  // 接続チェック
  // cerr << r << " " << c << " " << g[r][c] << endl;
  assert(g[r][c] == color);

  for (int i = 1; i <= 5; i++) {
    int nr = r + dr[dir] * i, nc = c + dc[dir] * i;
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) break;
    g[nr][nc] = color;
  }

  act.r = r;
  act.c = c;
  act.dir = dir;
}

void drawG(vector<vector<int>>& g, Action& act, int color) {
  int r = act.r;
  int c = act.c;
  int dir = act.dir;

  // 接続チェック
  assert(g[r][c] == color);

  for (int i = 1; i <= 5; i++) {
    int nr = r + dr[dir] * i, nc = c + dc[dir] * i;
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) break;
    g[nr][nc] = color;
  }
}

// 塗った結果のスコアへの影響
pair<int,int> tryDraw(int r, int c, int color, int dir, vector<vector<int>>& g, Action& act, const vector<vector<int>>& refg) {

  // 接続チェック
  assert(g[r][c] == color);

  int diff = 0;
  int drawn = 0;
  for (int i = 1; i <= 5; i++) {
    int nr = r + dr[dir] * i, nc = c + dc[dir] * i;
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) break;
    if (g[nr][nc] == color) continue; // 変化なし

    if (g[nr][nc] == -1) drawn++;
    if (refg[nr][nc] == color) diff++;
    if (refg[nr][nc] == g[nr][nc]) diff--;
  }

  act.r = r;
  act.c = c;
  act.dir = dir;
  return make_pair(diff, drawn);
}

Action simpleDraw(int r, int c, int color, vector<vector<int>>& g, const vector<vector<int>>& refg, int gx, int gy) {
  // 四方向に塗ってみて，一番塗れるところに塗る
  int max_diff = -1e8, max_draw_cnt = -1;
  Action max_action, act, max_draw_cnt_act;
  vector<int> draw_cnts(4);
  for (int dir = 0; dir < 4; dir++) {
    int nr = r + dr[dir], nc = c + dc[dir];
    if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;

    int diff, draw_cnt;
    tie(diff, draw_cnt) = tryDraw(r, c, color, dir, g, act, refg);
    draw_cnts[dir] = draw_cnt;
    // cerr << dirchar[dir] << " " << diff << " " << draw_cnt << endl;

    if (diff > max_diff) {
      max_diff = diff;
      max_action = act;
    }

    if (draw_cnt > max_draw_cnt) {
      max_draw_cnt = draw_cnt;
      max_draw_cnt_act = act;
    }
  }

  // 0のときはgx,gyに近づく方向に塗る
  if (max_diff <= 0) {
    if (gx == -1) return max_draw_cnt_act;

    int min_dist = 1e8;
    int min_dir = -1;
    for (int dir = 0; dir < 4; dir++) {
      int nr = r + dr[dir] * 3, nc = c + dc[dir] * 3;
      int dist = abs(gx - nc) + abs(gy - nr);
      if (min_dist > dist && draw_cnts[dir] > 0) {
        min_dist = dist;
        min_dir = dir;
      }
    }

    if (min_dist == -1) return max_draw_cnt_act;

    max_action.dir = min_dir;
    return max_action;
    // max_action = max_draw_cnt_act;
  }

  // cerr << "max_diff : " << max_diff << " " << endl;
  // cerr << "max_draw_cnt : " << max_draw_cnt << " " << endl;

  return max_action;
}

void showG(vector<vector<int>>& g) {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (g[r][c] == -1) cerr << '#';
      else cerr << g[r][c];
    }
    cerr << endl;
  }
}

pair<int,int> selectRC(int color, vector<vector<int>>& g, const vector<vector<int>>& refg, int& gx, int& gy) {
  // 起点から近い塗られていない箇所探す
  int oy, ox;
  if (color == 0) oy = 0, ox = 0;
  else if (color == 1) oy = 0, ox = N - 1;
  else if (color == 2) oy = N - 1, ox = 0;
  else if (color == 3) oy = N - 1, ox = N - 1;

  int sx = -1, sy = -1;
  {
    int min_dist = 1e8;
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (refg[r][c] == color && g[r][c] != color && g[r][c] == -1) {
          int dist = abs(r - oy) + abs(c - ox);
          if (dist < min_dist) {
            min_dist = dist;
            sy = r;
            sx = c;
          }
        }
      }
    }
  }
  gx = sx;
  gy = sy;

  if (sx == -1) {
    int min_dist = 1e8;
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (refg[r][c] == color && g[r][c] != color) {
          int dist = abs(r - oy) + abs(c - ox);
          if (dist < min_dist) {
            min_dist = dist;
            sy = r;
            sx = c;
          }
        }
      }
    }
  }
  // 面倒なので塗られていない部分に書き換える
  ox = sx;
  oy = sy;
  assert(ox != -1);

  int ret_r = -1, ret_c = -1;
  int min_dist = 1e8;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (g[r][c] == color) {
        // 4近傍チェック
        int diff_color_cnt = 0; // 隣接している色が異なるマス
        for (int dir = 0; dir < 4; dir++) {
          int nr = r + dr[dir], nc = c + dc[dir];
          if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
          if (g[nr][nc] != color && g[nr][nc] == -1) diff_color_cnt++;
        }
        // 基準からの距離を計算
        int dist = abs(r - oy) + abs(c - ox);
        if (dist < min_dist && diff_color_cnt > 0) {
          min_dist = dist;
          ret_r = r;
          ret_c = c;
        }
      }
    }
  }
  if (ret_r == -1) {
    // cerr << color << endl;
    // showG(g);
    return make_pair(-1, -1);
  }
  assert(ret_r != -1);

  return make_pair(ret_r, ret_c);
}

void solve(const vector<vector<int>>& refg) {
  vector<vector<int>> g(N, vector<int>(N, -1));
  g[0][0] = 0;
  g[0][N-1] = 1;
  g[N-1][0] = 2;
  g[N-1][N-1] = 3;
  vector<Action> ret(M);

  for (int m = 0; m < M; m++) {
    int r, c;
    int color = m % 4;
    int gx, gy;
    tie(r,c) = selectRC(color, g, refg, gx, gy); // どの位置から始めるか適当に決める
    if (r == -1) {
      ret[m].dir = -1;
    } else {
      ret[m] = simpleDraw(r, c, color, g, refg, gx, gy); // どの方向に塗るか適当に決める
    }
    if (r != -1)
      drawG(g, ret[m], color); // 実際に着色

    // cerr << ret[m].r << " " << ret[m].c << " " << dirchar[ret[m].dir] << endl;
  }

  for (int m = 0; m < M; m++) {
    const Action& act = ret[m];
    if (act.dir == -1) cout << -1 << endl;
    else cout << act.r << " " << act.c << " " << dirchar[act.dir] << endl;
  }

}

int main(void) {
  cin >> N >> M;

  vector<vector<int>> g(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> g[i][j];
    }
  }

  solve(g);

  return 0;
}