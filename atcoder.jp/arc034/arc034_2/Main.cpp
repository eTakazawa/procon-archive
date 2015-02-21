#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-8;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

ll f(ll x){
	ll ret = 0;
	while(x != 0){
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int main(void) {
	ll n;
	cin >> n;

	vector<ll> ans;
	ll i = max(n-500,0LL);
	for(;i<n;i++){
		if(n == i+f(i))ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}