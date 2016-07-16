#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long pow_mod(long long x, long long p){
	long long ret = 1;
	while(p){
		if(p%2==1){
			ret *= x;ret %= MOD;
		}
		p >>= 1;
		x *= x;
		x %= MOD;
	}
	return ret;
}

int main(void){
	long long n,k;
	cin >> n >> k;

	vector<long long> c(n+1);
	c[1] = 1;
	for(long long i=2;i<=n;i++){
		c[i] = c[i-1] * (k+i-2) % MOD * pow_mod(i-1,MOD-2) % MOD;
		c[i] %= MOD;
	}

	long long ret = 0;
	for(int i=1;i<=n;i++){
		ret += c[i];//*(n-i+1)%MOD;
		ret %= MOD;
	}
	cout << ret << endl;
	return 0;
}