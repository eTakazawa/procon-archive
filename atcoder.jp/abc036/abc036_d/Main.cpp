#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
vector<vector<int>> es;

long long dp[100010][2];
long long dfs(int v,int col,int prev=-1){
	if(dp[v][col] != -1)return dp[v][col];
	if(es[v].size() == 1 && es[v][0] == prev)return 1;
	long long ret = 1;
	for(int i=0;i<es[v].size();i++){
		int w = es[v][i];
		if(w == prev)continue;
		if(col == 0)
			ret *= dfs( w, 0, v) + dfs( w, 1, v);
		else
			ret *= dfs( w, 0, v);
		ret %= mod;
	}
	return dp[v][col] = ret;
}

int main(void){
	int N;
	cin >> N;
	es = vector<vector<int>>(N);
	for(int i=0;i<N-1;i++){
		int a,b;cin >> a >> b;
		a--;b--;
		es[a].push_back(b);
		es[b].push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	long long r1 = dfs( 0, 0);
	memset(dp,-1,sizeof(dp));
	long long r2 = dfs( 0, 1);
	cout << (r1+r2) % mod << endl;

	return 0;
}