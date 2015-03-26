#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	int mx = 0,mn = INF;
	for(int i=0;i<n/2;i++){
		mn = min(mn,a[i]+a[n-i-1]);
		mx = max(mx,a[i]+a[n-i-1]);
	}
	cout << mx-mn << endl;

	return 0;
}