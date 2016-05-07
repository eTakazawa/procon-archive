#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int main(void){
	
	int H,W;
	cin >> H >> W;
	vector<vector<int>> a(H,vector<int>(W));
	priority_queue<pair<int,pair<int,int>>> ord;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			scanf("%d",&a[i][j]);
			ord.push(make_pair(-a[i][j],make_pair(i,j)));
		}
	}

	vector<vector<long long>> dp(H,vector<long long>(W,1));

	while(!ord.empty()){
		int r = ord.top().second.first, c = ord.top().second.second;
		ord.pop();
		for(int i=0;i<4;i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nc < 0 || nr < 0 || nc >= W || nr >= H)continue;
			if(a[nr][nc] <= a[r][c])continue;
			dp[nr][nc] += dp[r][c];
			dp[nr][nc] %= (int)(1e9+7);
		}
	}

	long long ret = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			ret += dp[i][j];
			ret %= (int)(1e9+7);
		}
	}
	cout << ret << endl;
	return 0;
}