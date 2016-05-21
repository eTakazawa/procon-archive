#include <bits/stdc++.h>
using namespace std;

int main(void){
	double l,x,y,s,d;
	cin >> l >> x >> y >> s >> d;

	if( d == s){
		cout << 0 << endl;
	}
	else if( d > s ){
		double ret = (d-s)/(x+y);
		if(x < y){
			ret = min(ret,(s+l-d)/(y-x));
		}
		cout <<fixed << setprecision(10) << ret << endl;
	}else{
		double ret = (l-s+d)/(x+y);
		if(x < y){
			ret = min(ret,(s-d)/(y-x));
		}
		cout <<fixed << setprecision(10) << ret << endl;
	}

	return 0;
}