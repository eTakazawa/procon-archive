#include <bits/stdc++.h>
using namespace std;


int main(void){
	int n;
	cin >> n;
	vector<int> c(n);
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	double ret = 0;
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if( i == j )continue;
			if( c[i] % c[j] == 0 )cnt++;
		}
		if(cnt % 2 == 1)
			ret += 1./2;
		else
			ret += (cnt+2)/(2*cnt+2.);
	}
	cout << fixed << setprecision(10) << ret << endl;
	return 0;
}