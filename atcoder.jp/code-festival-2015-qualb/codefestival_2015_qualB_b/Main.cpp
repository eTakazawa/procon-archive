#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;
	vector<int> a(100010);
	for(int i=0;i<n;i++){
		int b;cin >> b;
		a[b]++;
	}

	int c = n/2;
	for(int i=0;i<100001;i++){
		if(a[i] > c){
			cout << i << endl;
			return 0;
		}
	}
	cout << '?' << endl;
	return 0;
}