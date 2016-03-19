#include <bits/stdc++.h>
using namespace std;
double X,Y;
vector<double> x,y,c;
double f(double val){
	double ret = 0;
	for(int i=0;i<x.size();i++){
		ret = max(ret, c[i]*abs(x[i]-val));
	}
	return -ret;
}
double f2(double val){
	double ret = 0;
	for(int i=0;i<x.size();i++){
		ret = max(ret, c[i]*max(abs(x[i]-X),abs(y[i]-val)));
	}
	// cout << val << " " << ret << endl;
	return -ret;
}
double search(double left, double right, int iteration){  
  for(int i=0;i<iteration;i++){  
    if(f((left*2+right)/3)>f((left+right*2)/3))  
      right=(left+right*2)/3;  
    else  
      left=(left*2+right)/3;  
  }  
  return (left+right)/2;  
}
double search2(double left, double right, int iteration){  
  for(int i=0;i<iteration;i++){  
    if(f2((left*2+right)/3)>f2((left+right*2)/3))  
      right=(left+right*2)/3;  
    else  
      left=(left*2+right)/3;
  }  
  return (left+right)/2;  
} 

int main(void){
	int n;
	cin >> n;
	
	bool end = false;
	x.resize(n);y.resize(n);c.resize(n);
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i] >> c[i];
	}

	double xi=1e9,xa=-1e9,yi=1e9,ya=-1e9;
	for(int i=0;i<n;i++){
		xi = min(xi,x[i]);
		yi = min(yi,y[i]);
		xa = max(xa,x[i]);
		ya = max(ya,y[i]);
	}
	X = 0;Y = 0;
	X = search(xi,xa,100);
	Y = search2(yi,ya,100);
	// cout << X << " " << Y << endl;
	double ret = 0;
	for(int i=0;i<n;i++){
		ret= max(ret,c[i]*max(abs(x[i]-X),abs(y[i]-Y)));
	}
	cout << fixed << setprecision(10) << ret << endl;
	return 0;
}