#include <iostream>
#include <vector>
using namespace std;

void toposort(int v, const vector<vector<int>>& es, vector<int>& visited, vector<int>& ret) {
  visited[v] = 1;
  for (int to : es[v]) {
    if (!visited[to]) toposort(to, es, visited, ret);
  }
  ret.push_back(v);
}

int main(void) {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> es(N);
  vector<int> visited(N), topo;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;y--;
    es[x].push_back(y);
  }

  for (int v = 0; v < N; v++) {
    toposort(v, es, visited, topo);
  }

  reverse(topo.begin(), topo.end());
  vector<int> dp(N);
  int res = 0;
  for (int u : topo) {
    for (int v : es[u]) {
      dp[v] = max(dp[v], dp[u] + 1);
      res = max(res, dp[v]);
    }
  }
  cout << res << endl;


  return 0;
}