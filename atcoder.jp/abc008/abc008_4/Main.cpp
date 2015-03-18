//金塊ゲーム、weekly CD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double EPS = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

//座標圧縮
int compress(vector<int>& X){
	vector<int> x = X;
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	for(int i=0;i<X.size();i++){
		X[i] = lower_bound(x.begin(),x.end(),X[i]) - x.begin();
		X[i]++;
	}
	return x.size();
}

int w,h;
vector<int> x,y;
map<int,int> px,py;
map<tuple<int,int,int,int>,int> memo;
int dfs(int l,int r,int u,int d){
	int res = 0;
	bool f = false;
	tuple<int,int,int,int> tp = make_tuple(l,r,u,d);
	if(memo.count(tp) != 0)return memo[tp];
	for(int i=0;i<x.size();i++){
		int ret = 0;
		if(l <= x[i] && x[i] <= r && u <= y[i] && y[i] <= d){
			if(x[i] != l){
				if(y[i] != u)
					ret += dfs(l,x[i]-1,u,y[i]-1);
				if(y[i] != d)
					ret += dfs(l,x[i]-1,y[i]+1,d);
			}
			if(x[i] != r){
				if(y[i] != u)
					ret += dfs(x[i]+1,r,u,y[i]-1);
				if(y[i] != d)
					ret += dfs(x[i]+1,r,y[i]+1,d);
			}
			f = true;
		}
		res = max(res,ret);
	}
	if(!f)return 0;
	return memo[tp] = res + (r-l+1)+(d-u+1)-1;
}

int main(void) {
	cin >> w >> h;
	int n;
	cin >> n;
	x.resize(n);y.resize(n);
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i];
	}

	cout << dfs(1,w,1,h) << endl;
	return 0;
}

