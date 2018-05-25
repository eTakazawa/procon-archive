#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int from, to, cost;
};
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<Edge> es, es_rev;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    es.push_back(Edge{a, b, c});
    es_rev.push_back(Edge{a, b, -c});
  }

  vector<long long> dist(n, 1e18);
  dist[0] = 0;
  for (int i = 0; i < 2*n; i++) {
    for (int j = 0; j < m; j++) {
      Edge& e = es_rev[j];
      int from = e.from, to = e.to;
      int cost = e.cost;
      if (dist[to] > dist[from] + e.cost) {
        dist[to] = dist[from] + e.cost;
        if (i >= n-1 && e.to == n-1) {
          cout << "inf" << endl;
          return 0;
        }
      }
    }
  }
  cout << -dist[n-1] << endl;
  return 0;
}