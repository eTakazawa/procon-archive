#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
	int n;
	long long an,a3=1,a2=0,a1=0;
	cin >> n;

	for(int i=4;i<=n;i++){
		an = a3%10007 + a2%10007 + a1%10007;
		a1 = a2;
		a2 = a3;
		a3 = an;
	}
if(n==1||n==2){cout << 0 << endl;return 0;}
if(n==3){cout << 1 << endl;return 0;}
	cout << an%10007 << endl;
	return 0;
}
