#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int main(void){
	string x,s,t;
	cin >> x >> s >> t;

	vector<long long> dp(x.size() + 1);
	dp[0] = 1LL;

	for(int i=0;i<x.size();i++){
		if(dp[i] == 0)continue;
		if(x.substr(i).find(s) == 0)
			dp[i + s.size()] += dp[i] % MOD;
		if(x.substr(i).find(t) == 0)
			dp[i + t.size()] += dp[i] % MOD;
	}

	cout << dp[x.size()] % MOD << endl;

	return 0;
}