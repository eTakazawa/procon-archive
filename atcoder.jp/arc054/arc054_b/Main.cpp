#include <bits/stdc++.h>
using namespace std;

double P;
double f(double x){
	return -(x + (P/(pow(2.0,x/1.5))));
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

int main(void){
	
	cin >> P;
	cout << fixed << setprecision(10) << -f(search(0.0,100.0,100000)) << endl;
	return 0;
}