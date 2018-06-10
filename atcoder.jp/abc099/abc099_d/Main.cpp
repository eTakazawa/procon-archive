#include <bits/stdc++.h>
using namespace std;
using Flow = int;
using Cost = int;
const int MAX_V = 100000;
const Cost INF = std::numeric_limits<Cost>::max() / 8;

struct PrimalDual {
    struct Edge {
        int d;
        Flow c, f;
        Cost w;
        int r, is_r;
        Edge(int d_, Flow c_, Flow f_, Cost w_, int r_, bool is_r_)
            : d(d_), c(c_), f(f_), w(w_), r(r_), is_r(is_r_) {}
    };

    int n;
    std::vector<std::vector<Edge> > g;
    PrimalDual(int n_) : n(n_), g(std::vector<std::vector<Edge> >(n_)) {}

    void add_edge(int src, int dst, Flow cap, Cost cost) {  // 有向辺
        int rsrc = g[dst].size();
        int rdst = g[src].size();
        g[src].emplace_back(dst, cap, 0, cost, rsrc, false);
        g[dst].emplace_back(src, cap, cap, -cost, rdst, true);
    }

    Cost solve(int s, int t, Flow f) {
        Cost res = 0;

        static Cost h[MAX_V + 10], dist[MAX_V];
        static int prevv[MAX_V + 10], preve[MAX_V + 10];
        // std::vector<Cost> h(g.size()), dist(g.size());
        // std::vector<int> prevv(g.size()), preve(g.size());

        using pcv = std::pair<Cost, int>;
        std::priority_queue<pcv, std::vector<pcv>, std::greater<pcv> > q;
        std::fill(h, h + n, 0);
        while (f > 0) {
            std::fill(dist, dist + n, INF);
            dist[s] = 0;
            q.emplace(0, s);
            while (q.size()) {
                Cost cd;
                int v;
                std::tie(cd, v) = q.top();
                q.pop();
                if (dist[v] < cd) continue;
                for (int i = 0; i < (int)(g[v].size()); ++i) {
                    Edge &e = g[v][i];
                    if (residue(e) == 0) continue;
                    if (dist[e.d] + h[e.d] > cd + h[v] + e.w) {
                        dist[e.d] = dist[v] + e.w + h[v] - h[e.d];
                        prevv[e.d] = v;
                        preve[e.d] = i;
                        q.emplace(dist[e.d], e.d);
                    }
                }
            }

            if (dist[t] == INF) return -1;  // 経路が見つからなかった

            // s-t 間最短路に沿って目一杯流す
            for (int i = 0; i < n; ++i) h[i] += dist[i];
            Flow d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = std::min(d, residue(g[prevv[v]][preve[v]]));
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                e.f += d;
                g[v][e.r].f -= d;
            }
        }
        return res;
    }

    Flow residue(const Edge &e) { return e.c - e.f; }

    // 流量を表示
    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)(g[i].size()); ++j) {
                Edge &e = g[i][j];
                if (e.is_r) continue;
                printf("%3d->%3d (flow:%d)\n", i, e.d, e.f);
            }
        }
    }
};

int main(void) {
  int N, C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C));
  vector<vector<int>> c(N, vector<int>(N));

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      cin >> D[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  PrimalDual mflow(40);
  for (int i = 1; i <= 3; i++) {
    mflow.add_edge(0, i, 1, 0);
  }

  int cost[3][31];
  memset(cost, 0, sizeof(cost));
  for (int k = 0; k < C; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cost[(i + j) % 3][k] += D[c[i][j]][k];
      }
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 0; j < C; j++) {
      mflow.add_edge(i, 4+j, 1, cost[i-1][j]);
      cerr << i << " " << 4+j << " " << cost[i-1][j] << endl;
      if (i == 1) mflow.add_edge(4+j, 39, 1, 0);
    }
  }
  // cerr << "max flow" << endl;
  cout << mflow.solve(0, 39, 3) << endl;
  // mflow.show();
  return 0;
}