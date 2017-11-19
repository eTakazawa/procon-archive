#include <bits/stdc++.h>
using namespace std;
 
struct Edge {
  int to, cost;
};
 
int widthEmb, widthOrg;
int orgV, orgE, embV, embE;
unordered_map<string, int> logs;
int orgMat[501][501];
int embMat[3601][3601];
int embid[61][61];
set<pair<int,int>> edges;
vector<vector<Edge>> es;
 
void makeIndex() {
  for (int i = 0; i < embV; i++) {
    embid[i / widthEmb][i % widthEmb] = i;
  }
}
void showEmb(vector<int>& emb) {
  for (int i = 0; i < embV; i++) {
    if (emb[i] != -1) {
      cout << emb[i] + 1 << " " << i + 1 << endl;
    }
  }
}
 
int evaluateAnswer(vector<int>& org2emb) {
  int sum = 0;
  for (auto& e : edges) {
    int embu = org2emb[e.first], embv = org2emb[e.second];
    if (embMat[embu][embv]) {
      sum += orgMat[e.first][e.second];
    }
  }
  return sum;
}
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int isout(int x, int y) {
  return (x < 0 || y < 0 || x >= widthEmb || y >= widthEmb) ? true : false;
}
int evaluateEmb(const vector<int>& emb) {
  int sum = 0;
  for (int i = 0; i < embV; i++) {
    if (emb[i] == -1) continue;
    int x = i % widthEmb, y = i / widthEmb; 
    for (int k = 0; k < 8; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      int ni = nx + ny * widthEmb;
      if (isout(nx, ny)) continue;
      if (emb[ni] == -1) continue;
      sum += orgMat[emb[i]][emb[ni]];
    }
  }
  return sum / 2;
}
 
int main(void) {
  chrono::system_clock::time_point start;
  start = chrono::system_clock::now();
 
  cin >> orgV >> orgE;
  es.resize(orgV);
  for (int i = 0; i < orgE; i++) {
    int u, v, w;
    cin >> u >> v >> w;u--;v--;
    orgMat[u][v] = orgMat[v][u] = w;
    edges.emplace(u, v);
    es[u].push_back(Edge{v, w});
    es[v].push_back(Edge{u, w});
  }
  cin >> embV >> embE;
  for (int i = 0; i < embE; i++) {
    int a, b;
    cin >> a >> b;a--;b--;
    embMat[a][b] = embMat[b][a] = 1;
  }
  widthEmb = sqrt(embV);
  widthOrg = sqrt(orgV);
  makeIndex();
 srand(time(NULL));
  vector<int> emb(embV, -1);
  map<int, int> embpoints;
  set<int> unused;
  for (int i = 0; i < orgV; i++)
    unused.insert(i);
  // todo: sumの部分を評価関数にする．
  int v = rand()%orgV; emb[embV / 2] = v; embpoints[v] = embV / 2; unused.erase(v);
  while (!unused.empty()) {
    // どの頂点をどこに置くか
    int maxsum = -1, maxv, maxe;
    for (int vi = 0; vi < orgV; vi++) {
      if (unused.find(vi) == unused.end()) continue;
      for (int ei = 0; ei < embV; ei++) {
        if (emb[ei] != -1) continue;
        int ex = ei % widthEmb, ey = ei / widthEmb;
        int sum = 0;
        for (int k = 0; k < 8; k++) {
          int nex = ex + dx[k], ney = ey + dy[k];
          if (isout(nex, ney)) continue;
          int nvi = emb[ney * widthEmb + nex];
          if (nvi == -1) continue;
          sum += orgMat[vi][nvi];
        }
        if (maxsum < sum) {
          maxsum = sum; maxv = vi; maxe = ei;
        }
      }
    }
    unused.erase(maxv); emb[maxe] = maxv; embpoints[maxv] = maxe;
  }
  // logs["before sa:"] = evaluateEmb(emb);
 
  // 焼き鈍しパート
  vector<int> ret = emb;
  int bestScore = evaluateEmb(ret);
  int nowScore = bestScore;
  int trycount = 0;
  int saMillTime = 9850;
 
  const auto saTimeStart = start;
  const auto saTimeEnd = saTimeStart + chrono::milliseconds(saMillTime);
  auto saTimeCurrent = chrono::system_clock::now();
  while ((saTimeCurrent = chrono::system_clock::now()) < saTimeEnd) {
    for (int loop=0;loop<100;loop++) {
      trycount++;
      int a = rand() % embV, b = rand() % embV;
      while (a == b || emb[a] == -1 || emb[b] == -1) {
        a = rand() % embV;
        b = rand() % embV;
      }
 
      swap(emb[a], emb[b]);
      int nextScore = evaluateEmb(emb);
      if (nextScore > bestScore) {
        bestScore = nextScore;
        ret = emb;
      } else { swap(emb[a], emb[b]); }
    }
  }
  showEmb(ret);
  // logs["best score: "] = evaluateEmb(emb);
  // logs["iter: "] = trycount;
  // for (auto& log : logs) {
  //   cerr << log.first << " " << log.second << endl;
  // }
  return 0;
}