#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
	}

	vector<int> dp(100002,1e9);
	dp[0] = 0;
	for(int i=0;i<N;i++){
		if(i>0)dp[i] = min( dp[i-1] + abs(a[i]-a[i-1]), dp[i]);
		if(i>1)dp[i] = min( dp[i-2] + abs(a[i]-a[i-2]), dp[i]);
	}
	cout << dp[N-1] << endl;
	return 0;
}