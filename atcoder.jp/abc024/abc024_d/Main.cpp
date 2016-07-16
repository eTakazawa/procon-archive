#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long mod_pow(long long x, long long p){
	long long ret = 1;
	while(p){
		if(p%2==1)ret *= x;
		ret %= MOD;
		x *= x;
		x %= MOD;
		p >>= 1;
	}
	return ret;
}

int main(void){
	long long A,B,C;
	cin >> A >> B >> C;

	//c = (BC - AB)/(AC - BC + AB)
	//r = (BC - AC)/(AB - BC + AC)


	long long cu = (B*C%MOD - A*B%MOD)%MOD;
	long long cd = (A*C%MOD - B*C%MOD + A*B%MOD)%MOD;
	long long c = cu * mod_pow(cd,MOD-2) % MOD;
	
	long long ru = (B*C%MOD - A*C%MOD)%MOD;
	long long rd = (A*B%MOD - B*C%MOD + A*C%MOD)%MOD;
	long long r = ru * mod_pow(rd,MOD-2) % MOD;

	while(r<0)r += MOD;
	while(c<0)c += MOD;
	cout << r << " " << c << endl;

	return 0;
}