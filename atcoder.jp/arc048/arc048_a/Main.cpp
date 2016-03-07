#include <bits/stdc++.h>
using namespace std;


int main(void){
	int a,b;
	cin >> a >> b;
	cout << b - a - (a<0&&b>0 ? 1 : 0) << endl;
	return 0;
}