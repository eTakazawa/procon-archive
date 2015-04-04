#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i=0;i<n;i++)
		cin >> h[i];

	vector<int> up(300001),down(300001);
	for(int i=1;i<n;i++){
		if(h[i] > h[i-1])up[i] = up[i-1] + 1;
	}
	for(int i=n-2;i>=0;i--){
		if(h[i] > h[i+1])down[i] = down[i+1] + 1;
	}
	
	int ret = 0;	
	for(int i=0;i<n;i++){
		ret = max(ret,up[i]+down[i]);
	}
	cout << ret+1 << endl;

	return 0;
}