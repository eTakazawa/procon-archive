#include <bits/stdc++.h>
using namespace std;

int main(void){
	int a,b;cin >> a >> b;
	if(a==1)a = 14;
	if(b==1)b = 14;

	if(a>b)cout << "Alice" << endl;
	else if(b>a)cout << "Bob" << endl;
	else cout << "Draw" << endl;
	return 0;
}