#include <bits/stdc++.h>
using namespace std;

struct Edge{
  string to;
  double cost;
  Edge(string to, double cost):to(to),cost(cost){}
};

int main(void) {
  int N;
  cin >> N;
  map<string, vector<Edge>> es;
  set<string> st;

  for (int i = 0; i < N; i++) {
    string large,small;
    int m;
    cin >> large >> m >> small;
    es[large].emplace_back(small, m);
    es[small].emplace_back(large, 1.0/m);
    st.insert(large);
    st.insert(small);
  }

  double Max = 0;
  pair<string, string> ans;
  for (auto start : st) {
    queue<pair<string, double>> que;
    set<string> used;
    
    que.emplace(start, 1);
    used.insert(start);

    while (!que.empty()) {
      string now;
      double cost;
      tie(now,cost) = que.front();que.pop();

      if (Max < cost) {
        Max = cost;
        ans = make_pair(start, now);
      }

      for (auto& edge : es[now]) {
        if (used.find(edge.to) != used.end()) continue;
        used.insert(edge.to);
        que.emplace(edge.to, cost*edge.cost);
      }
    }
    
  }

  cout << 1 << ans.first << "=";
  cout  << (int)round(Max);
  cout << ans.second << endl;

  return 0;
}