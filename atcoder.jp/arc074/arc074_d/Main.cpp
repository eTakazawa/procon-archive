#include <bits/stdc++.h>
using namespace std;
template<int V>
struct MaxFlow {
  using T = double;
  const T INF = 1<<28;

  struct Edge {
    int to,rev;
    T cap;
  };

  vector<Edge> g[V];
  int level[V];
  int iter[V];

  void add(int from, int to, T cap) {
    g[from].push_back(Edge{to, (int)g[to].size(), cap});
    g[to].push_back(Edge{from, (int)g[from].size()-1, 0});
  }
  void add_multi(int from, int to, T cap) {
    g[from].push_back(Edge{to, (int)g[to].size(), cap});
    g[to].push_back(Edge{from, (int)g[from].size()-1, cap});
  }

  void bfs(int s) {
    fill_n(level,V,-1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
      int v = que.front();
      que.pop();
      for(Edge e: g[v]) {
        if(e.cap <= 0)continue;
        if(level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }

  T dfs(int v,int t,T f) {
    if(v == t)return f;
    for(int &i = iter[v]; i < g[v].size(); i++) {
      Edge &e = g[v][i];
      if(e.cap <= 0)continue;
      if(level[v] < level[e.to]) {
        T d = dfs(e.to,t,min(f,e.cap));
        if(d <= 0)continue;
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
    return 0;
  }
  T exec(int s,int t) {
    T flow = 0;
    while(true) {
      bfs(s);
      if(level[t] < 0)return flow;
      fill_n(iter,V,0);
      T f;
      while((f = dfs(s,t,INF)) > 0) {
        flow += f;
      }
    }
  }
};

bool isleaf(char c){
  if(c == 'S' || c == 'T' || c == 'o')
    return true;
  return false;
}
int H,W;
int trIn(int i,int j){
  return i*W+j;
}
int trOut(int i,int j){
  return i*W+j + H*W;
}

int main(void) {
  cin >> H >> W;
  vector<string> a(H);
  for(int i=0;i<H;i++){
    cin >> a[i];
  }

  bool out = false;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a[i][j] == 'S'){
        for(int k=0;k<H;k++)
          if(a[k][j] == 'T')out = true;
        for(int k=0;k<W;k++)
          if(a[i][k] == 'T')out = true;
      }
    }
  }
  if(out){
    cout << -1 << endl;
    return 0;
  }

  // Graph g(10010);
  MaxFlow<20010> mf;
  int s,t;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a[i][j] == 'S')s = trOut(i,j);
      if(a[i][j] == 'T')t = trIn(i,j);

      if(isleaf(a[i][j])){
        mf.add(trIn(i,j),trOut(i,j),1);
        for(int k=0;k<H;k++){
          if(k == i)continue;
          if(isleaf(a[k][j])){
            mf.add(trOut(i,j), trIn(k,j), 1);
          }
        }
        for(int k=0;k<W;k++){
          if(k == j)continue;
          if(isleaf(a[i][k])){
            mf.add(trOut(i,j), trIn(i,k), 1);
          }
        }
      }
    }
  }
  

  cout << mf.exec(s,t) << endl;

  return 0;
}