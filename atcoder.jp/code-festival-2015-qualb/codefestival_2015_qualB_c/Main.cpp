#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<m;i++){
		cin >> b[i];
	}

	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());

	int ia = 0,ib = 0;
	bool f = true;
	while(1){
		if(a[ia] >= b[ib]){
			ia++;
			ib++;
		}else{
			ia++;
		}
		if(ib == b.size()){
			cout << "YES" << endl;
			return 0;
		}

		if(ia == a.size()){
			cout << "NO" << endl;
			return 0;
		}
	}

	return 0;
}