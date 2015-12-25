#include <bits/stdc++.h>
using namespace std;
int main(void){
	double a,b,c,d;
	cin >> a >> b >> c >> d;
	if(b/a < d/c){
		cout << "AOKI" << endl;
	}else if(b/a > d/c){
		cout << "TAKAHASHI" << endl;
	}else{
		cout << "DRAW" << endl;
	}
	return 0;
}