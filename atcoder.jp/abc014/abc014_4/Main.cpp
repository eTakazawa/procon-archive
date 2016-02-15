#include <bits/stdc++.h>
using namespace std;

class LCA{
public:
	int logn,n;
	bool isInit = false;
	vector<int> depth;
	vector<vector<int>> es;
	vector<vector<int>> parent;
	LCA(int n):n(n){
		logn = log2(n) + 1;
		es = vector<vector<int>>(n);
		parent = vector<vector<int>>(logn,vector<int>(n,-1));
		depth = vector<int>(n);
	}
	void add_edge(int u,int v){
		es[u].push_back(v);
		es[v].push_back(u);
		isInit = false;
	}
	void dfs(int u,int prev=-1,int d=0){
		depth[u] = d;
		parent[0][u] = prev;
		for(int v: es[u]){
			if( v == prev )continue;
			dfs( v, u, d+1);
		}
	}
	void init(){
		isInit = true;
		dfs(0);
		for(int i=0;i<logn-1;i++)for(int j=0;j<n;j++){
			if( parent[i][j] == -1 )parent[i+1][j] = -1;
			else parent[i+1][j] = parent[i][parent[i][j]];
		}
	}
	int calc(int u,int v){
		if(!isInit)init();
		if( depth[u] < depth[v] )swap(u,v);
		for(int i=0;i<depth[u]-depth[v];i++){
			if( ((depth[u]-depth[v]) >> i) & 1 )u = parent[i][u];
		}
		if( u == v )return u;
		for(int k=logn-1;k>=0;k--){
			if( parent[k][u] != parent[k][v] ){
				u = parent[k][u];	// 共通の親ではないので，そこより親にある(2^kより子ではない)
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	int getDistance(int u,int v){
		int w = calc(u,v);
		return depth[u]+depth[v]-depth[w]*2+1;
	}
};

int main(void){
	int n;cin >> n;
	LCA lca(n);
	for(int i=0;i<n-1;i++){
		int u,v;cin >> u >> v;
		lca.add_edge(u-1,v-1);
	}

	int q;cin >> q;
	for(int i=0;i<q;i++){
		int u,v;cin >> u >> v;
		cout << lca.getDistance(u-1,v-1) << endl;
	}

	return 0;
}
