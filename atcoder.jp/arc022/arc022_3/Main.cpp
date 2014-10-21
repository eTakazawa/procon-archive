#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include<utility>
#include<functional>
using namespace std;

vector<vector<int> > g;
vector<int> dist;

void dfs(int now,int pre,int d){
	dist[now] = d;
	for(int i=0;i<g[now].size();i++){
		if(g[now][i] == pre)continue;
		dfs(g[now][i],now,d+1);
	}
	return;
}

int main(void){
	int N;
	cin >> N;
	g.resize(N);
	dist.resize(N);
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0,-1,0);
	int pos1 = max_element(dist.begin(),dist.end()) - dist.begin();
	dfs(pos1,-1,0);
	int pos2 = max_element(dist.begin(),dist.end()) - dist.begin();
	cout << ++pos1 << " " << ++pos2 << endl;
	return 0;
}
