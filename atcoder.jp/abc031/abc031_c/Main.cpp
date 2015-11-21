#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}


	int ret = -1e9;
	for(int i=0;i<n;i++){
		int ao = -1e9,ch = -1e9;
		for(int j=0;j<n;j++){
			if(i == j)continue;
			vector<int> t;
			for(int k=0;k<n;k++){
				if(i<=k && k<=j || j<=k && k<=i){
					t.push_back(a[k]);
					// cout << a[k] << " ";	
				}
			}

			int aoki=0,chokudai = 0;
			for(int k=0;k<t.size();k++){
				if((k+1)%2==0){
					aoki += t[k];
				}else{
					chokudai += t[k];
				}
			}
			if( ao < aoki ){
				ao = aoki;
				ch = chokudai;
			}
		}
		ret = max(ret, ch);
	}
	cout << ret << endl;
	return 0;
}