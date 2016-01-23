#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> k(n-1);
	for(int i=0;i<n-1;i++){
		cin >> k[i];
	}
	vector<int> ret(n,-1);
	for(int i=0;i<n-2;i++){
		if(k[i] > k[i+1]){
			ret[i] = k[i];
			ret[i+1] = k[i+1];
		}else{
			ret[i+1] = k[i];
		}
	}
	ret[0] = k[0];
	ret[n-1] = k[n-2];
	for(int i=0;i<n;i++){
		cout << ret[i] << " ";
	}
	cout << endl;

	return 0;
}