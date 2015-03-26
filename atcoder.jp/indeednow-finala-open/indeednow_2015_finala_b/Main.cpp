#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(void) {
	int r,c;
	cin >> r >> c;
	int sx,sy,tx,ty;
	vector<string> a(r);
	for(int i=0;i<r;i++){
		cin >> a[i];
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j] == 's'){
				sx = j;
				sy = i;
				a[i][j] = '0';
			}else if(a[i][j] == 't'){
				tx = j;
				ty = i;
				a[i][j] = '0';
			}
		}
	}

	int dx[] = {-1,-1,0,1,0,-1};
	int dy[] = {0,-1,-1,0,1,1};
	int dx2[] = {-1,0,1,1,1,0};
	int dy2[] = {0,-1,-1,0,1,1};

	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	vector<vector<bool>> used(r,vector<bool>(c));
	pq.push(make_pair(0,make_pair(sy,sx)));
	while(!pq.empty()){
		pair<int,pair<int,int>> p = pq.top();pq.pop();
		int d = p.first;
		int y = p.second.first;
		int x = p.second.second;
		if(y == ty && x == tx){
			cout << d << endl;
			return 0;
		}
		for(int i=0;i<6;i++){
			int ny,nx;
			if(y%2 == 0){
				ny = y + dy[i];
				nx = x + dx[i];
			}
			else{
				ny = y + dy2[i];
				nx = x + dx2[i];
			}
			if(ny < 0 || nx < 0 || nx >= c || ny >= r || used[ny][nx])continue;
			pq.push(make_pair(d+a[ny][nx]-'0',make_pair(ny,nx)));
			used[ny][nx] = true;
		}
	}
	return 0;
}