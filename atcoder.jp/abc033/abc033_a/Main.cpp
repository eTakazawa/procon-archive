#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	cin >> s;
	bool same = true;
	for(int i=0;i<s.size()-1;i++){
		if(s[i] != s[i+1])same = false;
	}
	if(same)cout << "SAME" << endl;
	else cout << "DIFFERENT" << endl;
	return 0;
}