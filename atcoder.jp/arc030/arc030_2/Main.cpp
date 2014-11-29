#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

int dist[200];
int par[200];
int used[200];
int ans;

int dfs(int now,int prev,vector<vector<int> >&edge,vector<int>jewel){
	int ret = 0;
	for(int i=0;i<edge[now].size();i++){
		int next = edge[now][i];
		if(prev == next)continue;
		ret += dfs(next,now,edge,jewel);
	}
	if(ret == 0 && jewel[now] == 0)return 0;
	return ret + 2;
}

int main(void){
	int n,x;
	ans = 0;
	cin >> n >> x;
	x--;
	vector<vector<int> > edge(n);
	vector<int> jewel(n);
	int jp;
	for(int i=0;i<n;i++){
		int a;cin >> a;
		jewel[i] = a;
		if(a == 1)jp = i;
	}
	jewel[x] = 1;
	for(int i=0;i<200;i++)
		par[i] = i;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin >> a >> b;a--;b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int ans = dfs(x,-1,edge,jewel);
	ans -= 2;
	if(ans<0)ans = 0;
	cout << ans << endl;
	return 0;
}