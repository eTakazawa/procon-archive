#include <bits/stdc++.h>
using namespace std;

int main(void){
	int cnt = 0;
	for(int i=0;i<12;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			if(s[j] == 'r'){
				cnt++;
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}