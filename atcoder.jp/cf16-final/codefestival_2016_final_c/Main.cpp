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
	int M,N;
	cin >> N >> M;

	vector<vector<int>> L(N);
	UnionFind uf(M+1);

	for(int i=0;i<N;i++){
		int K;cin >> K;
		int ol = -1;
		for(int j=0;j<K;j++){
			int l;cin >> l;
			if(j == 0)ol = l;
			L[i].push_back(l);

			uf.unite( l, ol);
		}
	}

	// vector<set<int>> st(M+1);
	// for(int i=1;i<=M;i++){
	// 	st[uf.find(i)].insert(i);
	// }

	set<int> st;
	bool ok = true;
	for(int i=0;i<N;i++){
		if( i == 0 )for(int j=0;j<L[i].size();j++){
			st.insert( uf.find(L[i][j]) );
		}else{
			bool tmp = false;
			for(int j=0;j<L[i].size();j++){
				if( st.find(uf.find( L[i][j])) != st.end() )tmp = true;
			}
			if(!tmp)ok = false;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}