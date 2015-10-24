#include <bits/stdc++.h>
using namespace std;


int f(string s){
	int ret = 0;
	for(int i=0;i<(int)s.size()-4;i++){
		//cout << i << endl;
		if(s.substr(i,5) == "kyoto"){
			i += 4;
			ret++;
		}else if(s.substr(i,5) == "tokyo"){
			i += 4;
			ret++;
		}
	}
	return ret;
}
int main(void){
	int t;cin >> t;
	string s;
	for(int i=0;i<t;i++){
		cin >> s;
		cout << f(s) << endl;
	}
	return 0;
}
