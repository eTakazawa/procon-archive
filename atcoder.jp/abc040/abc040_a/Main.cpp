#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,x;
	cin >> n >> x;
	cout << min(n-x,x-1) << endl;
	return 0;
}