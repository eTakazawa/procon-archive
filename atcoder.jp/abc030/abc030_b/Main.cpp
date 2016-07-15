#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;

	double nn = ((n%12)+(m/60.))*(360./12);
	double mm = (m%60)*(360./60);
	cout << fixed << setprecision(10) << min(360-fabs(nn-mm),fabs(nn-mm)) << endl;
	return 0;
}