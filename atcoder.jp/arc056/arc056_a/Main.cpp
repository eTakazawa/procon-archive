#include <bits/stdc++.h>
using namespace std;
 
int main(void){
	long long a,b,k,l;
	cin >> a >> b >> k >> l;
	long long u = ceil(1.*k/l),d = floor(1.*k/l);
	cerr << u<< " " << d << endl;
	cout << min( b*u, b*d+(k-l*d)*a) << endl;
 
	return 0;
}
