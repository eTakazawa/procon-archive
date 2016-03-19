#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	int a,b,c,d;
	cin >> s >> a >> b >> c >> d;
	for(int i=0;i<=s.size();i++){
		if(i == a || i == b || i == c || i == d ){
			cout << "\"";
		}
		if( i < s.size())
			cout << s[i];
	}
	cout << endl;
	return 0;
}