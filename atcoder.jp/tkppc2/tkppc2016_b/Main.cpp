#include <bits/stdc++.h>
using namespace std;

long long dp[501];
int main(void){
	int N,M;
	cin >> N >> M;
	vector<int> v(N),t(N);
	for(int i=0;i<N;i++){
		cin >> v[i] >> t[i];
	}

	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for(int j=0;j<N;j++){
		for(int i=500;i>=0;i--){
			if(dp[i] == -1)continue;
			if(i+t[j] > 500)continue;
			dp[i+t[j]] = max(dp[i+t[j]],dp[i] + v[j]);
		}
	}

	long long ret = 0;
	for(int i=0;i<=M;i++){
		cerr << dp[i] << " ";
		ret = max(ret,dp[i]);
	}cerr << endl;
	cout << ret << endl;
	return 0;
}