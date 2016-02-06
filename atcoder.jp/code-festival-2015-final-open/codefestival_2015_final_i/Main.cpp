#include <bits/stdc++.h>
using namespace std;

struct edge{
	int to,cost;
};

template <class T>
struct fenwick_tree {
	vector<T> x;
	fenwick_tree(int n) : x(n, 0) { }
	T sum(int i, int j) {//両端を含む
  	if (i == 0) {
  		T S = 0;
  		for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
  			return S;
  	} else return sum(0, j) - sum(0, i-1);
  }
  void add(int k, T a) {
  	for (; k < x.size(); k |= k+1) x[k] += a;
  }
};

vector<int> L,P,max_height,heights,ranks;
vector<vector<edge>> es;
fenwick_tree<int> ft(100100);

void dfs(int x,int height = 0,int prev = -1){
	heights[x] = height;
	for(int i=0;i<es[x].size();i++){
		if(es[x][i].to == prev)continue;
		// cerr << x << " " << es[x][i].to << " " << es[x][i].cost << endl;
		dfs(es[x][i].to, height + es[x][i].cost, x);
	}
}
int dfs_max_height(int x,int prev = -1){
	int height = ranks[x];
	for(int i=0;i<es[x].size();i++){
		edge& e = es[x][i];
		if(e.to == prev)continue;
		height = max(height, dfs_max_height( e.to, x));
	}
	return max_height[x] = height;
}

set<int> st;
map<int,int> ans;
void solve(int x,int prev = -1){
	for(edge e: es[x]){
		if( e.to == prev )continue;
		ft.add(max_height[e.to],1);
	}
	// 自分のmax_heightより大きいものの数
	int sum = ft.sum( ranks[x]+1, 100099);

	// ansにxを残す時のコストを入れとく
	if(ans.find(heights[x]) == ans.end())ans[heights[x]] = sum;
	else ans[heights[x]] = min(ans[heights[x]], sum);
	// cerr << heights[x] << " " << sum << endl;

	for(edge e: es[x]){
		if( e.to == prev)continue;
		ft.add( max_height[e.to], -1);
		solve( e.to, x);
		ft.add( max_height[e.to], 1);
	}
	for(edge e: es[x]){
		if( e.to == prev)continue;
		ft.add( max_height[e.to], -1);
	}
}

int main(void){
	int n;
	cin >> n;
	L = vector<int>(n+1);
	P = vector<int>(n+1);
	es = vector<vector<edge>>(n+1);
	heights = vector<int>(n+1);
	max_height = vector<int>(n+1);

	for(int i=0;i<n;i++)
		cin >> L[i];

	es[0].push_back(edge{1, L[0]});
	es[1].push_back(edge{0, L[0]});
	for(int i=0;i<n-1;i++){
		int p;cin >> p;
		es[i+2].push_back(edge{p, L[i+1]});
		es[p].push_back(edge{i+2, L[i+1]});
		// cout << i+2 << " " << p << endl;
	}
	dfs(0);

	vector<int> hs = heights;
	ranks = vector<int>(n+1);
	sort(hs.begin(),hs.end());
	for(int i=0;i<=n;i++){
		ranks[i] = lower_bound(hs.begin(),hs.end(),heights[i])- hs.begin();
	}
	dfs_max_height(0);
	solve(0);

	int Q;
	cin >> Q;
	// cout << "Answer" << endl;
	for(int i=0;i<Q;i++){
		int q;cin >> q;
		if(ans.find(q) == ans.end())cout << -1 << endl;
		else cout << ans[q] << endl;
	}


	return 0;
}