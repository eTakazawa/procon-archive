#include <bits/stdc++.h>
using namespace std;

int A,B,sum;
vector<int> a,b;
int memo[2][1001][1001];
int dfs(int t,int i,int j){
	if(i == A && j == B) return 0;

	int& ret = memo[t%2][i][j];
	if(ret != -1)return ret;
	if(t%2==0){
		ret = -1e9;
		if(i < A)ret = max(ret, dfs(t+1,i+1,j) + a[i]);
		if(j < B)ret = max(ret, dfs(t+1,i,j+1) + b[j]);
	}else{
		ret = 1e9;
		if(i < A)ret = min(ret, dfs(t+1,i+1,j));
		if(j < B)ret = min(ret, dfs(t+1,i,j+1));
	}
	return ret;
}

int main(void){
	sum = 0;
	cin >> A >> B;
	a = vector<int>(A);
	b = vector<int>(B);
	for(int i=0;i<A;i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i=0;i<B;i++){
		cin >> b[i];
		sum += b[i];
	}
	memset(memo,-1,sizeof(memo));
	cout << dfs(0,0,0) << endl;

	return 0;
}