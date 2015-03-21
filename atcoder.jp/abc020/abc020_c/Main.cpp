#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool bfs(vector<vector<int>>& g,int sx,int sy,int tx,int ty,int x,int T){
	int h = g.size(),w = g[0].size();
	vector<vector<ll>> dist(h,vector<ll>(w,LONG_MAX/2));
	dist[sy][sx] = 0;
	queue<int>qx,qy;
	int d[] = {1,x};
	qx.push(sx);qy.push(sy);
	while(!qx.empty()){
		int x = qx.front(),y = qy.front();qx.pop();qy.pop();
		for(int i=0;i<4;i++){
			int nx = x+dx[i],ny = y+dy[i];
			if(nx >= w || ny >= h || ny < 0 || nx < 0)continue;
			if(dist[ny][nx] < dist[y][x] + d[g[ny][nx]])continue;
			dist[ny][nx] = dist[y][x] + d[g[ny][nx]];
			qx.push(nx);qy.push(ny);
		}
	}
	return dist[ty][tx] <= T;
}

int main(void) {
	int H,W,T;
	cin >> H >> W >> T;
	vector<string> vs(H);
	for(int i=0;i<H;i++){
		cin >> vs[i];
	}
	vector<vector<int>> g(H,vector<int>(W));
	int sx,sy,tx,ty;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(vs[i][j] == 'S'){
				g[i][j] = 0;
				sy = i;
				sx = j;
			}
			else if(vs[i][j] == 'G'){
				g[i][j] = 0;
				ty = i;
				tx = j;
			}
			else if(vs[i][j] == '.')g[i][j] = 0;
			else g[i][j] = 1;
		}
	}

	int low=1,hi=1e9,mid=0;
	while(hi > low+1){
		mid = (low + hi)/2;
		if(bfs(g,sx,sy,tx,ty,mid,T)){
			low = mid;
		}else{
			hi = mid;
		}
	}
	cout << low << endl;


	return 0;
}