#include <bits/stdc++.h>
using namespace std;

int main(void){
	int x = 0, N;
	string S;
	cin >> N >> S;

	int m = x;
	for(int i=0;i<S.size();i++){
		if( S[i] == 'I' )
			x++;
		else
			x--;
		m = max(m,x);
	}
	cout << m << endl;
	return 0;
}