#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

long long nCr[1000][1000];
int main(void){
	int n,k;
	cin >> n >> k; 
	int amari = k%n;
	int N = 500;
	long long nCr[N+10][N+10];
	nCr[0][0] = 1;
	for(int i=0;i<=N;i++) for(int j=0;j<i+1;j++) {
		nCr[i + 1][j] += nCr[i][j];
		nCr[i + 1][j + 1] += nCr[i][j];
    	nCr[i+1][j] %= 1000000007;
    	nCr[i+1][j+1] %= 1000000007;
	}
	if(n > k){
		cout << nCr[n+k-1][n-1] << endl;
	}else if(n==k){
		cout <<1 << endl;
	}else 

	cout << nCr[n][amari]%1000000007 << endl;
	return 0;
}