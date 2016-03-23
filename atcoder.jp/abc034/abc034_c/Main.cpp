#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;

long long power(long long a,long long n){
	long long ret = 1;
	for(int i=0;i<64;i++){
		if( (n>>i) & 1 )ret *= a;
		ret %= mod;
		a *= a;
		a %= mod;
	}
	return ret;
}

int main(void){
	long long w,h;
	cin >> w >> h;
	w--;h--;
	long long n = 1;
	for(long long i=w+1;i<=w+h;i++){
		n *= i;
		n %= mod;
	}

	for(long long i=1;i<=h;i++){
		n *= power(i,mod-2);
		n %= mod;
	}
	cout << n << endl;
	return 0;
}