#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<cmath>
using namespace std;

double x[1000],y[1000],d[1000];
int main(){
	double sx,sy,gx,gy,t,v;
	cin >> sx >> sy >> gx >> gy >> t >> v;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i];
		double tx = x[i] - sx, ty = y[i] - sy;
		double tx2 = x[i] -gx, ty2 = y[i] -gy;
		d[i] = sqrt(tx*tx + ty*ty )+ sqrt(tx2*tx2 + ty2*ty2);
	}
	int able = t*v;

	for(int i=0;i<n;i++){
		if(d[i] <= able){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}