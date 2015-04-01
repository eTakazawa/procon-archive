#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
const int INF = 1e9;
 
map<string,bool> dic;
bool is_palin(const string& s){
	if(dic.find(s) != dic.end())return dic[s];
	for(int i=0;i<s.size()/2;i++){
		if(s[i] != s[s.size()-1-i])return dic[s] = false;
	}
	return dic[s] = true;
}
 
int main(void) {
	int n;string s;
	cin >> n >> s;
	vector<ll> c(n);
	for(int i=0;i<n;i++){
		cin >> c[i];
	}

 	vector<vector<bool>> palin(5001,vector<bool>(5001));
 	for(int i=0;i<n;i++){
 		int d = 0;
 		while(i-d>=0 && i+d<n && s[i-d] == s[i+d]){
 			palin[i-d][i+d] = true;
 			d++;
 		}
 		int l = i-1,r = i;
 		while(l >= 0 && r < n && s[l] == s[r]){
 			palin[l][r] = true;
 			l--;r++;
 		}
 	}

	vector<ll> dp(s.size()+1,INF);
	dp[0] = c[0];
	for(int i=1;i<s.size();i++){
		dp[i] = min(dp[i] , dp[i-1] + c[0]);
		for(int j=0;j<i;j++){
			if(palin[j][i]){
				if(j==0)dp[i] = min(dp[i] , c[i-j]);
				else dp[i] = min(dp[i] , dp[j-1] + c[i-j]);
			}
		}
	}

	cout << dp[s.size()-1] << endl;
	return 0;
}