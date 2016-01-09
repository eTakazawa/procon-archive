#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,k;
	cin >> n >> k;
	vector<int> s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
		if(s[i] == 0){
			cout << n << endl;
			exit(0);
		}
	}

	int res = 0;
	long long tmp = 1;
	int l=0,r=0;
	while(r < n){
		// cout << l << " " << r << " " << tmp << endl;
		if(tmp > k){
			tmp /= s[l];
			l++;
			while(l > r){
				r++;
				tmp = s[r];
			}
		}else{
			tmp *= s[r];
			res = max(res,r-l);
			if(tmp <= k)
				res = max(res,r-l+1);
			r++;
		}
	}
	cout << res << endl;
	return 0;
}