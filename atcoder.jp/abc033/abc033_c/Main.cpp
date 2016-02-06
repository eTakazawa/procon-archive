#include <bits/stdc++.h>
using namespace std;




int main(void){
	string s;
	cin >> s;

	int cnt = 0;
	int a = 0;
	for(int i=0;i<s.size();i++){
		if( s[i] == '+' ){
			bool ok = false;
			while(a < i){
				if( s[a] == '0'){
					ok = true;
				}
				a++;
			}
			if(!ok){
				cnt++;
			}
			a = i + 1;
		}
	}
	bool ok = false;
	while(a < s.size()){
		if( s[a] == '0'){
					ok = true;
				}
				a++;
	}
	if(!ok){
				cnt++;
			}
	cout << cnt << endl;

	return 0;
}