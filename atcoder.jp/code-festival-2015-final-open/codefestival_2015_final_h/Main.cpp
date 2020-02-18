#include <bits/stdc++.h>
using namespace std;

#define MAX_V 100001
#define INF 1e18

struct Edge {
  int from, to, cost;
  bool operator < (const Edge& edge) const { return cost < edge.cost; }
  bool operator > (const Edge& edge) const { return cost > edge.cost; }
};

class Node {
public:
  int v;
  int cost;
  Node(int v, int cost) : v(v), cost(cost) {}
  bool operator < (const Node& node) const { return cost < node.cost; }
  bool operator > (const Node& node) const { return cost > node.cost; }
};

pair<vector<long long>,vector<long long>> Dijkstra(const vector<vector<Edge>>& es, int s) {
  vector<long long> dir(MAX_V, -1);
  vector<long long> dist(MAX_V, INF);
  vector<int> visited(MAX_V, 0);
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  pq.emplace(s, 0);
  dist[s] = 0;

  while (!pq.empty()) {
    Node node = pq.top(); pq.pop();
    int v = node.v;
    int cost = node.cost;

    if (visited[v]) continue;
    visited[v] = true;

    for (const auto& next_node : es[v]) {
      int nv = next_node.to;
      int node_cost = next_node.cost;
      if (visited[nv]) continue;
      long long next_cost = cost + node_cost;
      if (next_cost < dist[nv]) {
        dir[v] = nv;
        dist[nv] = next_cost;
        pq.emplace(nv, next_cost); // 最短経路更新出来れば更新
      }
    }
  }
  return make_pair(dist, dir);
}

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> s(N), l(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> l[i];
  }
  
  vector<vector<Edge>> es(M + 1);
  for (int i = 0; i < M; i++) {
    es[i].push_back(Edge{i, i + 1, 1});
    es[i + 1].push_back(Edge{i + 1, i, 1});
  }
  for (int i = 0; i < N; i++) {
    es[s[i]].push_back(Edge{s[i], s[i] + l[i], 0});
  }

  pair<vector<long long>,vector<long long>> ret;
  ret = Dijkstra(es, 0);
  cout << M - ret.first.at(M) << endl;

}