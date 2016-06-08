#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	string s;	

	while(n){
		if ( n & 1 ) s += "0";
		else s += "1";
		n /= 2;
	}

	bool ok = true;
	for(int i=0;i<s.size()/2;i++){
		if(s[i] != s[s.size() - i - 1])ok = false;
	}
	cerr << s << endl;
	if(ok)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}