#include <bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int> par;
  vector<int> sizes;
  UnionFind(int n):par(n),sizes(n,1){
    for(int i=0;i<n;i++)par[i] = i;
  }
  int find(int x){
    if(x == par[x])return x;
    return par[x] = find(par[x]);
  }
  void unite(int x,int y){
    x = find(x);y = find(y);
    if(x == y)return;
    if(sizes[x] < sizes[y])swap(x,y);
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x,int y){
    return find(x) == find(y);
  }
  int size(int x){
    return sizes[find(x)];
  }
};


int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
class Search{
public:
  int used[51][51];
  int maxpoint;
  vector<int> vx,vy;
  vector<int> bestvx,bestvy;
  vector<string> s;
  Search(vector<string> s){
    maxpoint = -1;
    this->s = s;
  }
  void init(){
    maxpoint = -1;
    vx = vector<int>();
    vy = vector<int>();
    bestvx = vector<int>();
    bestvy = vector<int>();
  }
  void dfs(int y,int x,int d,int point){
    if(d == 8) {
      if(point > maxpoint){
        maxpoint = point;
        bestvx = vx;
        bestvy = vy;
      }
      return;
    }
    for(int i=0;i<4;i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 50 || ny >= 50)continue;
      if(used[ny][nx] != 0)continue;
      if(s[ny][nx] == '0')continue;
      used[y][x] = 1;
      vx.push_back(x);vy.push_back(y);
      dfs(ny,nx,d+1,point * (s[y][x] - '0'));
      vx.pop_back();vy.pop_back();
      used[y][x] = 0;
    }
  }
  void bfs(int y,int x){
    queue<int> qx,qy;
    qx.push(x);qy.push(y);
    while(!qx.empty()){
      int xx = qx.front();qx.pop();
      int yy = qy.front();qy.pop();
      if(used[yy][xx])continue;
      bestvx.push_back(xx);
      bestvy.push_back(yy);
      used[yy][xx] = 1;
      if(bestvx.size() == 8)return;
      for(int i=0;i<4;i++){
        int nx = xx + dx[i];
        int ny = yy + dy[i];
        if(nx < 0 || ny < 0 || nx >= 50 || ny >= 50)continue;
        if(used[ny][nx] != 0)continue;
        if(s[ny][nx] == '0')continue;
        qx.push(nx);
        qy.push(ny);
      }
    }
  }
  void dfs7(int y,int x,int d,int point){
    if(d == 7) {
      if(point > maxpoint){
        maxpoint = point;
        bestvx = vx;
        bestvy = vy;
      }
      return;
    }
    for(int i=0;i<4;i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 50 || ny >= 50)continue;
      if(used[ny][nx] != 0)continue;
      if(s[ny][nx] == '0')continue;
      used[y][x] = 1;
      vx.push_back(x);vy.push_back(y);
      dfs(ny,nx,d+1,point * (s[y][x] - '0'));
      vx.pop_back();vy.pop_back();
      used[y][x] = 0;
    }
  }
  void run(){

    memset(used,0,sizeof(used));
    int col = 1;
    vector<vector<int>> vvx,vvy;
    for(int y=0;y<50;y++){
      for(int x=0;x<50;x++){
        init();
        if(used[y][x] != 0)continue;
        if(s[y][x] == '0')continue;
        // dfs(y,x,0,1);
        bfs(y,x);

        if(bestvx.size() != 8)continue;
        for(int i=0;i<8;i++){
          used[bestvy[i]][bestvx[i]] = col;
        }
        vvx.push_back(bestvx);
        vvy.push_back(bestvy);
        col++;
      }
    }

    vector<vector<int>> vvx7,vvy7;
    for(int y=0;y<50;y++){
      for(int x=0;x<50;x++){
        init();
        if(used[y][x] != 0)continue;
        if(s[y][x] == '0')continue;
        dfs7(y,x,0,1);

        if(bestvx.size() == 0)continue;
        vvx7.push_back(bestvx);
        vvy7.push_back(bestvy);
      }
    }

    cout << vvx.size() << endl;
    for(int i=0;i<vvx.size();i++){
      for(int j=0;j<8;j++){
        cout << vvy[i][j]+1 << " " << vvx[i][j]+1 << endl;
      }
    }
  }
};

int main(void){
	int H,W,K;
  cin >> H >> W >> K;
  vector<string> s(H);
  for(int i=0;i<H;i++){
    cin >> s[i];
  }

  Search search(s);
  search.run();

	return 0;
}