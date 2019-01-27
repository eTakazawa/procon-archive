#include <bits/stdc++.h>
using namespace std;

bool visit(const vector<vector<int>>& g, int v, vector<int> &order, vector<int> &color) {
  color[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int w = g[v][i];
    if (color[w] == 2) continue;
    if (color[w] == 1) return false;
    if (!visit(g, w, order, color)) return false;
  }
  order.push_back(v); color[v] = 2;
  return true;
}
bool topologicalSort(const vector<vector<int>>& g, vector<int>& order) {
  int n = g.size();
  vector<int> color(n);
  for (int u = 0; u < n; u++) {
    if (!color[u] && !visit(g, u, order, color)) {
      return false;
    }
  }
  reverse(order.begin(), order.end());
  return true;
}


int main(void) {
  int N, M;
  cin >> N >> M;
  int E = N - 1 + M;
  vector<vector<int>> chi(N);
  vector<vector<int>> par(N);

  int a, b;
  vector<vector<int>> es(N);
  for (int i = 0; i < E; i++) {
    cin >> a >> b;
    a--;b--;
    chi[a].push_back(b);
    par[b].push_back(a);
    es[a].push_back(b);
  }

  // vector<int> leaf;
  int root = -1;
  vector<int> depth(N, -1);
  for (int i = 0; i < N; i++) {
    if (par[i].size() == 0) {
      depth[i] = 0;
      root = i;
    }
  }

  vector<int> order;
  topologicalSort(es, order);
  for (int i = 0; i < N; i++) {
    int u = order[i];
    for (int v : es[u]) {
      depth[v] = depth[u] + 1;
    }
  }
  for (int v = 0; v < N; v++) {
    int p = -1, a = -1;
    // cerr << v << endl;
    for (int w : par[v]) {
      // cerr << w << " : " << depth[w] << endl;
      if (a < depth[w]) {
        p = w;
        a = depth[w];
      }
    }
    cout << p + 1 << endl;
  }

  return 0;
}