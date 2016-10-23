#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	cin >> s;

	int cnt = 0;
	for(int i=0;i<s.size();i++){
		if(!cnt && s[i] == 'C'){
			cnt++;
		}else if(cnt == 1 && s[i] == 'F'){
			cnt++;
		}
	}
	if(cnt == 2)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}