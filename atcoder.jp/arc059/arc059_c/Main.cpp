#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long pow_mod(long long a,int k){
	long long ret = 1;
	while(k){
		if(k & 1){
			ret *= a;
			ret %= MOD;
		}
		a *= a;
		a %= MOD;
		k >>= 1;
	}
	return ret;
}

long long dp[401][401],c[401][401],tb[401][401];
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N,C;
	cin >> N >> C;
	vector<long long> A(N),B(N);
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<N;i++)
		cin >> B[i];

	for(int i=1;i<=400;i++){
		for(int j=0;j<=400;j++){
			tb[i][j] = pow_mod(i,j);
		}
	}
	// c[i][j] := i番目の奴をj乗した奴の累積和
	for(int i=0;i<N;i++){
		for(int j=A[i];j<=B[i];j++){
			for(int k=0;k<=C;k++){
				c[i][k] += tb[j][k]; //pow_mod(j,k);
				c[i][k] %= MOD;
			}
		}
	}

	dp[0][0] = 1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=C;j++){
			for(int k=0;k<=j;k++){
				dp[i][j] += dp[i-1][k] * c[i-1][j-k];//* pow_mod(A[i-1],j-k);
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[N][C] << endl;

	return 0;
}