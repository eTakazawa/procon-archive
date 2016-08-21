#include <bits/stdc++.h>
using namespace std;

int main(void){
	string S;
	cin >> S;
	int n,s,e,w;
	n = s = e = w = 0;
	for(int i=0;i<S.size();i++){
		if( S[i] == 'N' )n++;
		else if( S[i] == 'S' )s++;
		else if( S[i] == 'E' )e++;
		else if( S[i] == 'W' )w++;
	}

	if( s > 0 && n == 0 || s == 0 && n > 0 ||
		e > 0 && w == 0 || e == 0 && w > 0 )
		cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}