#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int dist[11];
vector<int> rel[11];

void bfs(int s){
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int i=0;i<rel[now].size();i++){
			int nx = rel[now][i];
			if(dist[nx] == -1){
				dist[nx] = dist[now] + 1;
				q.push(nx);
			}
		}
	}
}

int main(void){
	int n,m;
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		rel[a].push_back(b);
		rel[b].push_back(a);
	}

	for(int i=0;i<n;i++){
		bfs(i);
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(dist[j] == 2)cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}