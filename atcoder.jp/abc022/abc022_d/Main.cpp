#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(void){
	int n;
	cin >> n;
	vector<int> ax(n),ay(n),bx(n),by(n);
	double gx=0,gy=0;
	for(int i=0;i<n;i++){
		cin >> ax[i] >> ay[i];
		gx += ax[i];
		gy += ay[i];
	}
	gx = gx/n;
	gy = gy/n;
	double agl = 0;
	for(int i=0;i<n;i++){
		agl += sqrt((gx-ax[i])*(gx-ax[i]) + (gy-ay[i])*(gy-ay[i]));
	}

	gx = gy = 0;
	for(int i=0;i<n;i++){
		cin >> bx[i] >> by[i];
		gx += bx[i];
		gy += by[i];
	}
	gx = gx/n;
	gy = gy/n;
	double bgl = 0;
	for(int i=0;i<n;i++){
		bgl += sqrt((gx-bx[i])*(gx-bx[i]) + (gy-by[i])*(gy-by[i]));
	}
	//cout << agl << " " << bgl << endl;
	printf("%.10f\n",bgl/agl);
	return 0;
}
