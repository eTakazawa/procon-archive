#include <bits/stdc++.h>
using namespace std;

int main(void){
	int x;
	cin >> x;

	int ret = 0;
	for(int i=0;i<=1000;i++){
		if( i*i*i*i == x ){
			ret = i;
			break;
		}
	}
	cout << ret << endl;
	return 0;
}