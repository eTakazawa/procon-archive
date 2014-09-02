#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define INF 1000000000


int dp[2000][1000];
int main(){
	int R,G,B;
	cin >> R >> G >> B;
	for (int i = 0; i < 2000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][R+G+B] = 0;
	for(int i=-1000;i<999;i++){
		for(int j=R+G+B;j>=1;j--){
			if(dp[i+1000][j] == INF)continue;
			dp[i+1001][j] = min(dp[i+1001][j],dp[i+1000][j]);
			dp[i+1001][j-1] = min(dp[i+1000][j-1],dp[i+1000][j] + (j>G+B ? abs(-100-i) : ((j>B)? abs(0-i) : abs(100-i))) );
		}
	}
	int ret = INF;
	for(int i=0;i<2000;i++){
		ret = min(ret,dp[i][0]);
	}
	cout << ret << endl;
	return 0;
}
