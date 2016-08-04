#include <bits/stdc++.h>
using namespace std;
struct UnionFind{
	vector<int> par,sz;
	UnionFind(){};
	UnionFind(int n) : par(n),sz(n,1) {
		for(int i=0;i<n;i++)
			par[i] = i;
	}
	int root(int x){
		if(par[x] == x)return x;
		return par[x] = root(par[x]);
	}
	bool unite(int x,int y){
		x = root(x);
		y = root(y);
		if(x == y)return false;
		if(sz[x] < sz[y]) swap(x,y);
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	bool find(int x,int y){
		return root(x) == root(y);
	}
	int query(int x,int y){
		x = root(x);
		y = root(y);
		if(x == y)return sz[x];
		else return sz[x] + sz[y];
	}
};

int N,M,Q;
vector<int> a,b;
vector<int> x,y,z;
vector<int> ans;
vector<UnionFind> ufs(50);
vector<int> pos(50);
void dfs(int l,int r,vector<int> v,int d){
	if(l == r){
		for(int i : v)
			ans[i] = l;
		return;
	}

	int mid = (l + r) / 2;
	// //cerr << "b:" << pos[d] << endl;
	for(int i=pos[d];i<=mid;i++){
		ufs[d].unite(a[i],b[i]);
	}
	pos[d] = mid + 1;
	// cerr << "a:" << pos[d] << endl;
	// cerr << d << " " << pos[d] << endl;

	//cerr << l << " " << r << " " << mid << endl;
	//cerr << v.size() << endl;
	vector<int> lv,rv;
	//cerr << "d:" << d << endl;
	for(int i : v){
		//cerr << i << ":" << ufs[d].query(x[i],y[i]) << endl;
		if(ufs[d].query(x[i],y[i]) >= z[i]){
			lv.push_back(i);
		}
		else rv.push_back(i);
	}
	dfs(l,mid,lv,d+1);
	dfs(mid+1,r,rv,d);
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i=0;i<50;i++)
		ufs[i] = UnionFind(N);

	a.resize(M);b.resize(M);
	for(int i=0;i<M;i++){
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}
	cin >> Q;
	x.resize(Q);y.resize(Q);z.resize(Q);
	for(int i=0;i<Q;i++){
		cin >> x[i] >> y[i] >> z[i];
		x[i]--;y[i]--;
	}

	ans.resize(Q);
	vector<int> v(Q);
	for(int i=0;i<Q;i++)
		v[i] = i;

	dfs(0,M-1,v,0);
	for(int i=0;i<ans.size();i++){
		cout << ans[i] + 1 << endl;
	}

	return 0;
}