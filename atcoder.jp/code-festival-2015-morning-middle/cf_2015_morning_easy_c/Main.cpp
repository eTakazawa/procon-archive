#include <bits/stdc++.h>
using namespace std;

int main(void){
	long long n,k,m,r;
	cin >> n >> k >> m >> r;
	vector<long long> s(n-1);
	for(int i=0;i<n-1;i++){
		cin >> s[i];
	}
	s.push_back(0);
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());

	long long sum = 0,k1=0;
	for(int i=0;i<k;i++){
		sum += s[i];
		if(i!=k-1)k1+=s[i];
	}

	if((double)sum/k < r){
		if(r*k-k1 > m)
			cout << -1 <<endl;
		else
			cout << r*k-k1 << endl;

	}else{
		cout << 0 << endl;
	}

	return 0;
}