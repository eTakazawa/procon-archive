#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>
#include<cctype>
#include<climits>
#include<ctime>
#define INF INT_MAX

using namespace std;


int d[100][100];
int main() {
	int n;
	int b;
	int a[3];
	cin >> n;
	for(int i=0;i<3;i++){
		cin >> a[i];
		if(n == a[i]){
			cout << "NO" << endl;
			return 0;
		}
	}

	for(int i=0;i<100;i++){
		if(n-3 != a[0] && n-3 != a[1] && n-3 != a[2]){
			n-=3;
		}else if(n-2 != a[0] && n-2 != a[1] && n-2 != a[2]){
			n -= 2;
		}else if(n-1 != a[0] && n-1 != a[1] && n-1 != a[2]){
			n-= 1;
		}
		if(n<=0){
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}