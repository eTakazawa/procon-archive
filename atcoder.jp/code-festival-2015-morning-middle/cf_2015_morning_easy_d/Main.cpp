#include <bits/stdc++.h>
using namespace std;

int n;
int f(string s,string t){
	vector<vector<int>> dp(n+2,vector<int>(n+2));
	for(int i=0;i<s.size();i++){
		for(int j=0;j<t.size();j++){
			if(s[i] == t[j]){
				dp[i+1][j+1] = dp[i][j] + 1;
			}else{
				dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j]);
				dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);
			}
		}
	}
	// for(int i=0;i<=s.size();i++){
	// 	for(int j=0;j<=t.size();j++){
	// 		cout << dp[i][j] << " ";
	// 	}cout << endl;
	// }
	return dp[(int)s.size()][(int)t.size()];
}

int main(void){
	string s;
	cin >> n >> s;
	// cout << f("abcd","bcd") << endl;

	//区切り
	int ret = n;
	for(int i=0;i<n;i++){
		// cout << s.substr(0,i) << " " << s.substr(i) << endl;
		// cout << f(s.substr(0,i),s.substr(i)) << endl;
		ret = min(ret,n-f(s.substr(0,i),s.substr(i))*2);
	}
	cout << ret << endl;

	return 0;
}