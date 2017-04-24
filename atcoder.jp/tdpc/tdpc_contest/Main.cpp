#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> p(N);
	for(int i=0;i<N;i++){
		cin >> p[i];
	}

	vector<int> dp(100*100+1);
	dp[0] = 1;
	for(int i=0;i<N;i++){
		for(int j=100*100+1;j>=p[i];j--){
			if(dp[j-p[i]])
				dp[j] = dp[j-p[i]];
		}
	}
	int ret = 0;
	for(int i=0;i<100*100+1;i++){
		if(dp[i])ret++;
	}
	cout << ret << endl;
	return 0;
}
