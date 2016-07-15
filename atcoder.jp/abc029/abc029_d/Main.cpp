#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	cin >> N;

	// N / 10 + min(1,N%10-1)
	// N / 100 * 10 + min(10, N%100-10) 

	long long ret = 0;
	for(int i=1;i<=9;i++){
		int n = pow(10,i);
		// cout << n << endl;
		ret += N / n * (n/10) + max(0,min(n/10, N%n-n/10+1));
		// cout << ret << endl;
	}
	cout << ret << endl;
	return 0;
}