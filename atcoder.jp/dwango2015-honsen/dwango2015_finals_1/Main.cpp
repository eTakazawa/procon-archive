//ドワンゴ　フィッシング　8020
//写経させて頂きました
//http://dwango2015-honsen.contest.atcoder.jp/submissions/337867

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int N,X;
string s;
int dp[303][303][303][2];
//x文字目
//n個にこにー文字列がある
//m個にこにー文字列が連続
//a 0:'5'だった(又はにこにー文字列が終わってる)　1:'2'だった
int dfs(int x,int n,int m,int a){
	n = min(255,n);
	m = min(255,m);

	if(dp[x][n][m][a] != -1)return dp[x][n][m][a];
	if(x == s.size())return n >= X;
	vector<int> p;
	if(s[x] == '?')for(int i=0;i<10;i++)p.push_back(i);
	else p.push_back(s[x] - '0');

	int ans = 0;
	for(int i=0;i<p.size();i++){
		int t = p[i];
		if(a == 0 && t == 2){
			ans += dfs(x+1,n,m,1);
		}else if(a == 1 && t == 5){
			ans += dfs(x+1,n+m+1,m+1,0);
		}else if(t == 2){
			ans += dfs(x+1,n,0,1);
		}else{
			ans += dfs(x+1,n,0,0);
		}
		ans %= MOD;
	}

	return dp[x][n][m][a] = ans % MOD;
}

int main(void) {	
	memset(dp,-1,sizeof(dp));
	cin >> N >> X >> s;
	cout << dfs(0,0,0,0) << endl;

	return 0;
}

