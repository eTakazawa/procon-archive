#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	string p,q,r;
	string ans;
	for(int i=0;i<n;i++){
		cin >> p >> q >> r;
		if(p == "BEGINNING"){
			ans += r[0];
		}else if(p == "MIDDLE"){
			ans += r[r.size()/2];
		}else{
			ans += r[r.size()-1];
		}
	}
	cout << ans << endl;
    return 0;
}