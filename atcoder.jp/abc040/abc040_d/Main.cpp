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

int main(void){
	cin.tie(0);
ios::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	map<int,vector<pair<int,int>>> mp;
	for(int i=0;i<M;i++){
		int a,b,y;cin >> a >> b >> y;
		a--;b--;
		mp[y].push_back(make_pair(a,b));
	}

	int Q;
	cin >> Q;
	vector<int> v(Q),w(Q);
	map<int,vector<int>> qs;
	map<pair<int,int>,int> ans;
	for(int i=0;i<Q;i++){
		cin >> v[i] >> w[i];v[i]--;
		qs[w[i]].push_back(v[i]);
	}

	UnionFind uf(N);
	int eid = 0;
	for(int y=200000;y>=0;y--){
		for(int i=0;i<qs[y].size();i++){
			ans[make_pair(qs[y][i],y)] = uf.size(qs[y][i]);
		}

		for(int i=0;i<mp[y].size();i++){
			uf.unite(mp[y][i].first,mp[y][i].second);
		}
	}

	for(int i=0;i<Q;i++){
		cout << ans[make_pair(v[i],w[i])] << endl;
	}

	return 0;
}