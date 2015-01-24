#include <bits/stdc++.h>
#define INF INT_MAX / 2
#define MOD 1000000007

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int>> PIPII;
typedef long long ll;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int dp[100002];
int main(void) {
	string s;
	cin >> s;

	int sum = 0;
	for(int i=0;i<s.size()-1;i++){
		dp[i+1] = dp[i];
		if(s[i] == '2' && s[i+1] == '5'){
			sum++;
			dp[i+1] += sum;
			dp[i+2] = dp[i+1];
			i++;
		}else{
			sum = 0;
		}
	}
	cout << dp[s.size()-1] << endl;
	return 0;
}

// command shift d duplicate
// command ctrl up down
// command D
// command caps G → '' ""
// vector<vector<int>> a(N,vector<int>(M,-1));
//diff < (./a.out < input.txt) output.txt
