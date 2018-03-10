#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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
    typedef pair<int,int> pii;
    struct edge{ int to, cap, cost, rev;};
    vector<vector<edge>> G;
    vector<int> h, dist, prevv, preve;
    int V;
    const int inf = 1e9;

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
const int N = 40, K = 1000;
void dijkstra(int y, int x, 
  const vector<vector<int>>& g, vector<vector<int>>& d,
  vector<vector<pii>>& prev) {
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
      if (g[ny][nx]) continue;
      if (d[ny][nx] > d[vy][vx] + g[ny][nx]) {
        d[ny][nx] = d[vy][vx] + g[ny][nx];
        que.push(T(d[ny][nx], ny, nx));
        prev[ny][nx] = make_pair(vy, vx);
      }
    }
  }
}
vector<pii> srcs, dsts;
const int INF = 1e9;

vector<pii> createLines() {
  vector<pii> ret;
  ret.emplace_back(0, N / 2);
  for (int i = 1; i < 39; i++) {
    if (i == N/1) continue;
    ret.emplace_back(N / 2, i);
    ret.emplace_back(i, N / 2);
  }
  return ret;
}
vector<pii> createLines2() {
  vector<pii> ret;
  int cnt = 0;
  int r = N / 2;
  int breadth = 2;
  for (int i = N-1; i > 0; i--) {
    ret.emplace_back(r, i);
  }
  for (int d = 1; d <= 7; d++) {
    for (int i = 0; i < N - 1; i++) {
      int j = i;
      if (cnt % 2 != 0) j = N - i - 1;
      ret.emplace_back(r + d*breadth, j);
    }
    for (int i = 0; i < N - 1; i++) {
      int j = i;
      if (cnt % 2 != 0) j = N - i - 1;
      ret.emplace_back(r - d*breadth, j);
    }
    cnt++;
  }

  return ret;
}

int main(void) {
  int dummy;
  cin >> dummy >> dummy;
  for (int i = 0; i < K; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    srcs.emplace_back(a, b);
    dsts.emplace_back(c, d);
  }
  vector<pii> initLines = createLines2();

  vector<vector<int>> grid(N, vector<int>(N, 0));
  set<pii> cracks;
  int count1 = 0, initLID = 0, threshold = 30;
  for (int i = 0; i < K; i++) {
    int a = srcs[i].first, b = srcs[i].second;
    int c = dsts[i].first, d = dsts[i].second;
    
    if (initLID < initLines.size()) {
      // if (grid[a][b] + grid[c][d] == 1 && abs(a-b)+abs(c-d) > threshold) {
      //   pii p(a,b);
      //   if (grid[c][d]) p = pii(c,d);
      // }
      int r = initLines[initLID].first, c = initLines[initLID].second;
      initLID++;
      cout << r << " " << c << endl;
      grid[r][c] ^= 1;
    } else {
      if (grid[a][b] + grid[c][d] == 1 && cracks.size() == 0) {
        pii p(a,b);
        if (grid[c][d]) p = pii(c,d);
        cout << p.first << " " << p.second << endl;
        cracks.emplace(p.first, p.second);
      } else if (cracks.size() > 0) {
        auto p = *cracks.begin();
        cout << p.first << " " << p.second << endl;
        cracks.erase(p);
      }else {
        cout << "-1 -1" << endl;
      }
      
    }
    // cerr << "turn " << i << " : ";
    // if (grid[a][b] + grid[c][d] == 2) count1++;
    // cerr << grid[a][b] + grid[c][d] << endl;

    // vector<vector<int>> distance(N, vector<int>(N, INF));
    // vector<vector<pii>> prev(N, vector<pii>(N));
    // dijkstra(a, b, grid, distance, prev);
  }
  // cerr << count1 << endl;
  // cerr << instone << endl;
  // java Generator -seed 12345 > input.txt
  // java Judge input.txt output.txt
  return 0;
}