#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> x,y;
int a[17][17];
long long memo[17][1<<16+1];
bool check(int bit,int add){
	for(int i=0;i<N;i++){
		if(bit & (1<<i)){
			if( a[add][i] == -1 )return false;
		}
	}
	return true;
}
long long dfs(int n,int bit){
	if(n == N)return 1;
	if( memo[n][bit] != -1 )return memo[n][bit];
	long long ret = 0;
	for(int i=0;i<N;i++){
		if( bit & (1<<i) )continue;
		if(!check(bit,i))continue;
		ret += dfs( n+1, bit | (1<<i));
	}
	return memo[n][bit] = ret;
}

int main(void){
    cin >> N >> M;
    x = vector<int>(M);
    y = vector<int>(M);
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<M;i++){
    	cin >> x[i] >> y[i];
    	x[i]--;y[i]--;
    	a[x[i]][y[i]] = 1;
    	a[y[i]][x[i]] = -1;
    }
    cout << dfs(0,0) << endl;
    return 0;
}