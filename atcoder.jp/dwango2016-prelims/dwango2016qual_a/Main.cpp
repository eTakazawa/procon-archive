#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> a = {25,2525,252525,25252525};
	int ret =0;
	for(int i=0;i<a.size();i++){
		ret += max(n,n / a[i]);
	}
	cout << n/25 << endl;
	return 0;
}