#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	vector<int> a = {25,39,51,76,163,111,136,128,133,138};
	vector<int> dp(1001);

	dp[0] = 1;
	for(int j=0;j<a.size();j++){
		for(int i=1000;i>=0;i--){
			if(i-a[j] >= 0){
				if(dp[i-a[j]] == 1){
					dp[i] = 1;
				}
			}
			if(j == 6){
				if(i-58 >= 0){
				if(dp[i-58] == 1){
					dp[i] = 1;
				}
			}
			}
		}
	}

	for(int i=0;i<1001;i++){
		if(dp[i]==1){
			cout << i << endl;
		}
	}

	return 0;
}
