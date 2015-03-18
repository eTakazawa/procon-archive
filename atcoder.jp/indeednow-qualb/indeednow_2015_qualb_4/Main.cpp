#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(void) {
	int n,c;
	cin >> n >> c;
	vector<int>a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
 
	vector<ll> dp(n+1);
	vector<int> d(n+1);
	for(int i=0;i<a[i];i++){
		if(a[i] < 1 || a[i] > c)a[i] = 0;
	}
	// int ret = 0;
	// for(int i=0;i<n;i++){
	// 	if(a[i] == k){
	// 		dp[i] += i+1 + d * (i+1-d);
	// 		d = i+1;
	// 		ret = dp[i];
	// 	}else if(i == n-1){
	// 		dp[i] += (d>0?dp[d-1]:0) + d * (i+1-d);
	// 	}
	// }
 
	for(int i=0;i<n;i++){
		dp[a[i]] += i+1 + (ll)d[a[i]] * (i-d[a[i]]);
		d[a[i]] = i+1;
		if(i == n-1){
			for(int j=1;j<=n;j++){
				if(j == a[i]){
					//dp[i][a[i]] += i+1 + d[a[i]] * (i+1-d[a[i]]);
				}else{
					dp[j] +=  (ll)d[j] * (i+1-d[j]);
				}
			}
		}
		//cout << i+1 << " " << dp[2] << endl;
	}
 
	for(int i=1;i<=c;i++){
		cout << dp[i] << endl;		
	}
 
	return 0;
}