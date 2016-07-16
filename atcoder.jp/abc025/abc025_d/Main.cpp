#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
vector<int> emptyX,emptyY;
int exist[26],existX[26],existY[26];

bool check(int state,int pNumber,int px,int py,int k){
	vector<vector<int>> used(5,vector<int>(5));
	// 既に入っているところ
	for(int i=0;i<k;i++){
		if( state & (1<<i) ){
			used[emptyY[i]][emptyX[i]] = 1;
		}
	}
	// 盤面に挿れる，数字まで
	for(int i=1;i<pNumber;i++){
		if(exist[i]){
			used[existY[i]][existX[i]] = 1;
		}
	}
	// 既に入っていたら駄目
	if(used[py][px])return false;
	{
		int cnt = 0;
		for(int i=-1;i<=1;i++){
			int nx = px + i;
			if(nx < 0 || nx >= 5){
				cnt = 10;
				break;
			}
			if(used[py][nx] == 1)cnt++;
		}
		if(cnt == 1)return false;
	}
	{
		int cnt = 0;
		for(int i=-1;i<=1;i++){
			int ny = py + i;
			if(ny < 0 || ny >= 5){
				cnt = 10;
				break;
			}
			if(used[ny][px] == 1)cnt++;
		}
		if(cnt == 1)return false;
	}
	return true;
}

int main(void){
	vector<vector<int>> bd(5,vector<int>(5));
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> bd[i][j];
		}
	}

	int k = 0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(bd[i][j] == 0){
				emptyX.push_back(j);
				emptyY.push_back(i);
				k++;
			}else{
				exist[bd[i][j]] = 1;
				existX[bd[i][j]] = j;
				existY[bd[i][j]] = i;
			}
		}
	}

	vector<long long> dp(1<<k);
	dp[0] = 1;
	for(int i=1;i<=25;i++){
		vector<long long> _dp(1<<k);
		for(int s=0;s<(1<<k);s++){
			if(dp[s] == 0)continue;

			if(exist[i] == 1){
				if(check(s,i,existX[i],existY[i],k)){
					_dp[s] += dp[s];
					_dp[s] %= MOD;
				}
			}else{
				for(int j=0;j<k;j++){
					if(s & (1<<j))continue;
					if(check(s,i,emptyX[j],emptyY[j],k)){
						_dp[s | (1<<j)] += dp[s];
						_dp[s | (1<<j)] %= MOD;
					}
				}
			}

		}
		dp = _dp;
	}
	cout << dp[(1<<k)-1] << endl;
	return 0;
}