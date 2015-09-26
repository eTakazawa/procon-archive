#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int sum = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			a[i] *= 2;
		}
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}