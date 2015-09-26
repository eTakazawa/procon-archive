#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,t;
	cin >> n >> t;
	vector<int> a(n),b(n),c(n);

	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		c[i] = a[i] - b[i];
		sum += a[i];
	}
	int dif = sum - t;
	sort(c.begin(),c.end(),greater<int>());

	int cnt = 0;
	for(int i=0;i<n;i++){
		if(dif > 0){
			dif -= c[i];
			cnt++;
		}
	}
	if(dif > 0)cout << -1 << endl;
	else cout << cnt << endl;

	




	return 0;
}