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
#include<climits>
#define INF INT_MAX

using namespace std;

int main(){
	int d[7],j[7];
	for(int i=0;i<7;i++){
		cin >> d[i];
	}
	for(int i=0;i<7;i++){
		cin >> j[i];
	}
	int ret=0;
	for(int i=0;i<7;i++){
		ret += d[i]>j[i] ? d[i] : j[i];
	}

	cout << ret << endl;

	return 0;
}