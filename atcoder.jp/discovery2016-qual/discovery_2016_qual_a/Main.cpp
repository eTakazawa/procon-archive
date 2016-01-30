#include <bits/stdc++.h>
using namespace std;

int main(void){
	int w;
	cin >> w;
	string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";

	for(int i=0;i<s.size();i++){
		if(i%w==0 && i != 0)cout << endl;
		cout << s[i];
	}
	cout << endl;
	return 0;
}