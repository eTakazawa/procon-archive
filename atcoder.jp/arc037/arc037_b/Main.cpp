#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

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
	int n,m;
	cin >> n >> m;
	UnionFind uf(n);
	vector<bool> tree(n,true);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;u--;v--;
		if(uf.same(u,v)){
			tree[u] = false;
			tree[v] = false;
			tree[uf.find(u)] = false;
			tree[uf.find(v)] = false;
		}
		uf.unite(u,v);
	}

	int cnt = 0;
	set<int> st;
	for(int i=0;i<n;i++){
		if(tree[uf.find(i)] && st.find(uf.find(i)) == st.end())cnt++;
		st.insert(uf.find(i));
	}
	cout << cnt << endl;
	return 0;
}