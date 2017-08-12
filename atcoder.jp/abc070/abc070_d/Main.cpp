#include <bits/stdc++.h>
using namespace std;

struct edge{
  int to;
  long long cost;
  edge(int to,long long cost):to(to),cost(cost){}
};
vector<long long> distances;
vector<vector<edge>> es;
void dfs(int u,int prev=-1,long long dist=0) {
  distances[u] = dist;
  for(const edge& e: es[u]) {
    if( e.to == prev )continue;
    dfs( e.to, u, dist+e.cost );
  }
}
int main(void) {
  int N;
  cin >> N;
  es = vector<vector<edge>>(N);
  distances = vector<long long>(N);
  for(int i=0;i<N-1;i++){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    es[a].emplace_back(b,c);
    es[b].emplace_back(a,c);
  }
  int Q,K;
  cin >> Q >> K;
  K--;
  dfs(K);
  int x,y;
  for(int i=0;i<Q;i++){
    cin >> x >> y;x--;y--;
    cout << distances[x] + distances[y] << endl;
  }

  return 0;
}