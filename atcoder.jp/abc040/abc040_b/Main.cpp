#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,ret = 1e9;
	cin >> n;
	for(int i=1;i<=n;i++){
		int j = n/i;
		if(i*j > n)continue;
		int rem = n - (i*j);
		ret = min(ret, rem + abs(i-j) );
	}
	cout << ret << endl;
	return 0;
}