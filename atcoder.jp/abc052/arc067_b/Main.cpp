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
	long long N,A,B;
	cin >> N >> A >> B;
	vector<long long> x(N);
	for(int i=0;i<N;i++){
		cin >> x[i];
	}

	UnionFind uf(N);
	long long ret = 0;
	for(int i=0;i<N-1;i++){
		long long cost = A*(x[i+1]-x[i]);
		if( B > cost ){
			uf.unite(i,i+1);
			ret += cost;
		}
	}

	set<int> st;
	for(int i=0;i<N;i++){
		st.insert(uf.find(i));
	}

	cout << ret + (B * (st.size()-1)) << endl;

	return 0;
}
