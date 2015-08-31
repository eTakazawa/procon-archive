#include <bits/stdc++.h>
using namespace std;

double A,B,C;
double f(double t){
	return A * t + B * sin(C*t*M_PI);
}

int main(void){
	cin >> A >> B >> C;
	double low,high,mid;
	low = 0;
	high = 1000;
	for(int i=0;i<1000;i++){
		mid = (low+high)/2;
		if(f(mid)<100)low = mid;
		else high = mid;
	}
	cout << fixed << setprecision(10) << low << endl;
	return 0;
}