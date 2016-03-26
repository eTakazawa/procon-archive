#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	cin >> s;
	int t;cin >> t;

	int x=0,y=0,h=0;
	for(int i=0;i<s.size();i++){
		if(s[i] == 'L')x--;
		if(s[i] == 'R')x++;
		if(s[i] == 'U')y++;
		if(s[i] == 'D')y--;
		if(s[i] == '?')h++;
	}

	if(t == 1){
		cout << abs(x)+abs(y)+h << endl;
	}else{
		if(abs(x)+abs(y)-h < 0){
			cout << abs(abs(x)+abs(y)-h)%2 << endl;
		}else{
			cout << abs(x)+abs(y)-h << endl;	
		}
	}

	return 0;
}