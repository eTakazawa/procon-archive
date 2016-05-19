#include <iostream>
#include <string>
#include <vector>
 
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
int main(void)
{
	int N,Q;
	cin >> N >> Q;
	UnionFind uf(100001);

	for(int i=0;i<Q;i++){
		int q,a,b;
		cin >> q >> a >> b;
		if(q){
			if(uf.same(a,b))cout << "Yes" << endl;
			else cout << "No" << endl;
		}else{
			uf.unite(a,b);
		}
	}
	return 0;
}