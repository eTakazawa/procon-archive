#include <bits/stdc++.h>
using namespace std;

long long dfs(long long a,long long b,int t){
	if( b == 0 ){
		if(t != 2)return -a;
		return 0;
	}
	// cout << "r:" << a << " " << b << endl;
	// cout << (a/b) * 2 * b << " " << ( ((a%b!=0) && (t%2==1)) ?b:0)  << endl;
	return (a/b) * 2 * b + ( ((a%b!=0) && (t==1)) ?b:0 ) + dfs( b, a%b, t+1);
}

int main(void){
	long long n,x;
	cin >> n >> x;
	cout << dfs(x,n-x,1)+x << endl;

	return 0;
}