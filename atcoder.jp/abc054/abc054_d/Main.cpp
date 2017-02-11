#include <bits/stdc++.h>
using namespace std;

long long dp[1001][1001];

int main(void){
	int N,Ma,Mb;
	cin >> N >> Ma >> Mb;
	vector<int> a(N),b(N),c(N);
	for(int i=0;i<N;i++){
		cin >> a[i] >> b[i] >> c[i];
	}

	long long INF = 1e18;
	for(int i=0;i<=1000;i++)for(int j=0;j<=1000;j++)
		dp[i][j] = INF;

	dp[0][0] = 0;
	for(int k=0;k<N;k++){
		for(int i=1000;i>=0;i--){
			for(int j=1000;j>=0;j--){
				if(i-a[k] < 0 || j-b[k] < 0)continue;
				if(dp[i-a[k]][j-b[k]] == INF)continue;
				dp[i][j] = min(dp[i-a[k]][j-b[k]] + c[k],dp[i][j]);
			}
		}
	}

	long long ret = INF;
	for(int i=1;i<=100;i++){
		ret = min(ret,dp[Ma*i][Mb*i]);
	}
	if(ret == INF)cout << -1 << endl;
	else cout << ret << endl;

	return 0;
}