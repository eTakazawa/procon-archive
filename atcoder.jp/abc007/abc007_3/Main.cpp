#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(void){
	int R,C;
	cin >> R >> C;
	int sy,sx,gy,gx;
	cin >> sy >> sx;
	cin >> gy >> gx;

	int dist[52][52];
	memset(dist,0,sizeof(dist));

	vector<string> maze(R);
	for(int i=0;i<R;i++)
		cin >> maze[i];

	sx--;sy--;gx--;gy--;

	queue<int> qx,qy;
	qx.push(sx);qy.push(sy);
	maze[sy][sx] = '#';

	while(!qx.empty()){
		int x = qx.front();qx.pop();
		int y = qy.front();qy.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if( maze[ny][nx] == '#' )continue;
			maze[ny][nx] = '#';
			dist[ny][nx] = dist[y][x] + 1;
			qx.push(nx);
			qy.push(ny);
		}
	}

	cout << dist[gy][gx] << endl;

	return 0;
}