#include <bits/stdc++.h>
using namespace std;

int N,W;
vector<int>v,w;
long long dfs(int n,long long wt){
	if(wt > W)return -1e18;
	if(n >= N)return 0LL;
	return max(dfs(n+1,wt+w[n])+v[n],dfs(n+1,wt));
}


int main(void){
	cin >> N >> W;
	v.resize(N);w.resize(N);
	int max_v=0,max_w=0;
	for(int i=0;i<N;i++){
		cin >> v[i] >> w[i];
		max_v = max(max_v,v[i]);
		max_w = max(max_w,w[i]);
	}

	
	long long ret = 0;
	if(max_v <= 1000){
		vector<long long> dp(200100,1e18);
		dp[0] = 0;
		for(int i=0;i<N;i++){
			for(int j=200099;j>=0;j--){
				if(dp[j] == 1e18)continue;
				if(j + v[i] >= 200099)continue;
				dp[j+v[i]] = min(dp[j+v[i]],dp[j]+w[i]);
			}
		}
		for(long long i=0;i<200100;i++){
			if(dp[i] <= W)ret = max(ret,i);
		}
	}else if(max_w <= 1000){
		vector<long long> dp(200100,-1);
		dp[0] = 0;
		for(int i=0;i<N;i++){
			for(int j=200099;j>=0;j--){
				if(dp[j] == -1)continue;
				if(j + w[i] >= 200099)continue;
				dp[j+w[i]] = max(dp[j+w[i]],dp[j]+v[i]);
			}
		}
		for(int i=0;i<min(W+1,200100);i++){
			ret = max(ret, dp[i]);
		}
	}else{
		cout << dfs(0,0LL) << endl;
		return 0;
	}
	cout << ret << endl;
	return 0;
}