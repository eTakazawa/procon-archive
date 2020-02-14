#include <bits/stdc++.h>
using namespace std;

#define N 50
#define W 50
#define H 50
#define INF 1e8

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
};

template<class T = int>
class Node_ {
public:
  Point p;
  T cost;
  Node_(int x, int y, T cost) : p(x, y), cost(cost) {}
  bool operator < (const Node_& node) const { return cost < node.cost; }
  bool operator > (const Node_& node) const { return cost > node.cost; }
};

using Node = Node_<int>;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/**
 * g: 2次元グリッド (vector<vector<int>>)
 * p: 開始位置
 * 
 * g[y][x]
 *  -1    : 行き止まり
 *  その他 : そのマスを踏んだときのコスト
 **/
vector<vector<int>> dijkstra(const vector<string>& g, const Point& p) {
  
  vector<vector<int>> dist(H, vector<int>(W, INF));
  vector<vector<int>> visited(H, vector<int>(W, 0));
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  map<char, int> char_to_cost{
    {'#', -1},
    {'.', 1}
  };

  pq.emplace(p.x, p.y, 0);
  dist[p.y][p.x] = 0;

  while (!pq.empty()) {
    const Node node = pq.top(); pq.pop();
    int x = node.p.x, y = node.p.y;
    int cost = node.cost;

    if (visited[y][x]) continue;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
      if (visited[ny][nx]) continue;

      int cell_cost = char_to_cost[g[ny][nx]];
      if (cell_cost == -1) continue;

      int next_cost = cost + cell_cost;
      if (next_cost < dist[ny][nx]) {
        dist[ny][nx] = next_cost;
        pq.emplace(nx, ny, next_cost); // 最短経路更新出来れば更新
      }
    }
  }
  return dist;
}

int main(void) {
  int R, C;
  int sx, sy, gx, gy;

  cin >> R >> C;
  cin >> sy >> sx;
  cin >> gy >> gx;
  sx--;sy--;gx--;gy--;

  vector<string> g(R);
  for (int r = 0; r < R; r++) {
    cin >> g[r];
  }

  vector<vector<int>> dist = dijkstra(g, Point(sx, sy));
  cout << dist[gy][gx] << endl;

  return 0;
}