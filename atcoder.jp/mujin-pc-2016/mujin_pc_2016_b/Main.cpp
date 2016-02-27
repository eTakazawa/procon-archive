#include <bits/stdc++.h>
using namespace std;

int main(void){
	double a,b,c;
	// double M_PI = 3.14159265359;
	cin >> a >> b >> c;

	double r1 = a+b+c;
	double r2 = max(max(a-(b+c),c-(a+b)),(b-(a+c)));
	if( r2 < 0 )r2 = 0.0;
	
	cout << fixed << setprecision(10) << (r1*r1*M_PI) - (r2*r2*M_PI) << endl;

	return 0;
}