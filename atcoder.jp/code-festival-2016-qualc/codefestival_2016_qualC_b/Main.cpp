#include <bits/stdc++.h>
using namespace std;

int main(void){
	int K,T;
	cin >> K >> T;
	vector<int> a(T);
	for(int i=0;i<T;i++){
		cin >> a[i];
	}

	sort(a.begin(),a.end(),greater<int>());
	int rem = K - a[0];

	cout << max(0,a[0] - 1 - rem) << endl;

	return 0;
}