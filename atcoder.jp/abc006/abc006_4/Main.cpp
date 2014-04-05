#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define INF 30000

using namespace std;

int dp[30000];
int main(){
	int N,c[30001];
	cin >> N;

	for(int i=0;i<N;i++){
		cin >> c[i];
		dp[i]=300000;
	}
	for(int i=0;i<N;i++){
		*lower_bound(dp,dp+N,c[i]) = c[i];
	}
	printf("%d\n",N-(lower_bound(dp,dp+N,300000)-dp));
	return 0;
}
