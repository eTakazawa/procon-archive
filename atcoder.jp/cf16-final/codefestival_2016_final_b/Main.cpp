#include <bits/stdc++.h>
using namespace std;


int check(int m,int N){
	vector<int> dp(10000001);
	for(int j=1;j<=m;j++){
		for(int i=N;i>=0;i--){
			if(dp[i] && i+j<=N)dp[i+j] = 1;
		}
	}
	if(dp[N])return true;
	else return false;
}
int main(void){
	int N;
	cin >> N;

	int sum = 0,m;
	for(int i=1;i<=N;i++){
		sum += i;
		if( sum >= N ){
			m = i;
			break;
		}
	}
	// cout << m << endl;

	while(m != 0){
		if( N - m >= 0){
			N -= m;
			cout << m << endl;
		}
		m--;
	}

	return 0;
}