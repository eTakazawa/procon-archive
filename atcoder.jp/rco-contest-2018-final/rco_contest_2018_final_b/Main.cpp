#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
struct timeval timer_begin, timer_end;
int timer_called;
inline void timer_start() 
{
  timer_called++;
  gettimeofday(&timer_begin, NULL);    
}     
inline double timer_now() 
{         
  timer_called++;
  gettimeofday(&timer_end, NULL);         
  return timer_end.tv_sec - timer_begin.tv_sec +
    (timer_end.tv_usec - timer_begin.tv_usec)/1000000.0;     
}
unsigned int randxor(){
    static unsigned int x=123456789,y=362436009,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}
struct min_cost_flow {
    const int inf = 1e9;
    typedef pair<int,int> pii;
    struct edge{ int to, cap, cost, rev;};
    vector<vector<edge>> G;
    vector<int> h, dist, prevv, preve;
    int V;

    min_cost_flow(int V) : V(V) {
        G.assign(V, vector<edge>());
        h.assign(V, 0);
        dist.assign(V, 0);
        prevv.assign(V, 0);
        preve.assign(V, 0);
    }

    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
    }

    int run(int s, int t, int f) {
        int res = 0;
        while(f > 0){
            priority_queue<pii, vector<pii>, greater<pii>> que;
            fill(begin(dist), end(dist), inf);
            dist[s] = 0;
            que.push(pii(0, s));
            while(!que.empty()){
                pii p = que.top(); que.pop();
                int v = p.second;
                if(dist[v] < p.first) continue;
                for(int i = 0; i < (int)G[v].size(); ++i) {
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(pii(dist[e.to], e.to));
                    }
                }
            }
        }
        if(dist[t] == inf) return -1;
        for(int v = 0; v < V; ++V) h[v] += dist[v];
        int d = f;
        for(int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * h[t];
        for(int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
        return res;
    }
};
const int N = 50;
void dijkstra(int y, int x, const vector<vector<int>>& g, vector<vector<int>>& d) {
  priority_queue<T, vector<T>, greater<T>> que;
  d[y][x] = 0;
  que.push(T(0, y, x));
  while (!que.empty()) {
    T t = que.top();
    que.pop();
    int vy = get<1>(t), vx = get<2>(t);
    if (d[vy][vx] < get<0>(t)) continue;
    for (int i = 0; i < 4; i++) {
      int ny = vy + dy[i], nx = vx + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
      if (d[ny][nx] > d[vy][vx] + g[ny][nx]) {
        d[ny][nx] = d[vy][vx] + g[ny][nx];
        que.push(T(d[ny][nx], ny, nx));
      }
    }
  }
}
int match(char *t, char *p) {
  int n = strlen(t), m = strlen(p);
  int M[0x100]; fill(M, M+0x100, 0);
  int count = 0;
  for (int i = 0; i < m; ++i) M[p[i]] |= (1 << i);
  for (int i = 0, S = 0; i < n; ++i) {
    S = ((S << 1) | 1) & M[t[i]];
    if (S & (1 << (m-1))) {
      ++count; // match at t[i-m+1 ... i]
      return i - m + 1;
    }
  }
  return -1;
  // return count;
}
// int lcs(string X,string Y){
//   int c[N+1][N+1];
//   int m=X.length();
//   int n=Y.length();
//   int maxl=0;
//   X= " " +X;
//   Y= " " +Y;
//   for (int i = 0; i <= m; ++i) {c[i][0]=0; }
//   for (int j = 0; j <= n; ++j) {c[0][j]=0; }
//   int start = -1;
//   for (int i = 1; i <= m; ++i) {
//       for (int j = 1; j <= n; ++j) {
//           if(X[i]==Y[j]){
//               c[i][j]=c[i-1][j-1]+1;

//           }else{
//               c[i][j]=max(c[i-1][j],c[i][j-1]);
//           }
//           if (maxl < c[i][j]) {

//           }
//           maxl=max(maxl,c[i][j]);
//       }
//   }
//   return maxl;
// }
int main(void) {
  int N, M, Q;
  cin >> N >> M >> Q;
  string S = "";
  string scaleS = "";
  char prev = '_', prevprev = '_';
  int range = 10;
  for (int i = 0; i < N / range; i++) {
    char ad  = 'a' + randxor() % 26;
    while(prev == ad) ad  = 'a' + randxor() % 26;
    S += string(range, ad);
    scaleS += ad;
    prev = ad;
  }
  // cerr << S << endl;
  // cerr << S << endl;
  cout << S << endl << 3 << endl;
  vector<string> qi(Q);
  for (int i = 0; i < Q; i++) {
    cin >> qi[i];
  }
  char* t = const_cast<char*>((scaleS+scaleS).c_str());
  for (int i = 0; i < Q; i++) {
    string q = qi[i] ,qq = q;
    qq.erase(unique(qq.begin(), qq.end()), qq.end());
    int m = match(t, const_cast<char*>(qq.c_str()));
    if (q[0] == q[1] && q[1] == q[2]) cout << (m == -1 ? 0 : m % N) * range + range/3 << endl;
    else cout << (m == -1 ? 0 : m % N) * range + range/2 << endl;
  }
  return 0;
}