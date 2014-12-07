#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define MAX_N 100

vector<int> par[MAX_N];	//親
bool used[MAX_N];
int cnt;

void bfs(int v){
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		int n = q.front();q.pop();
		used[n] = true;
		for(int i = 0 ;i < par[n].size();i++){
			int nx = par[n][i];
			if(used[nx] == false){
				q.push(nx);
				used[nx] = true;
				cnt++;
			}
		}
	}
}

int main(void){
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a,b;
		cin >> a >> b;a--;b--;
		par[b].push_back(a);
	}
	bfs(0);
	cout << cnt+1 << endl;

	return 0;
}
