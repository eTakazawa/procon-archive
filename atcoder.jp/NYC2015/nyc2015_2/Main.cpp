#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),greater<int>());

	int count = 1;
	int w = a[0];
	a[0] = -1;
	for(;;){
		int remMax = 0,index = -1;
		for (int i = 0; i < n; ++i) {
			if(a[i] == -1)continue;
			int rem = min( w - a[i], a[i] );
			if( rem > remMax ){
				index = i;
				remMax = rem;
			}
		}
		if(index == -1)break;
		count++;
		cerr << a[index] << endl;
		w = remMax;
		a[index] = -1;
	}
	cout << count << endl;
	return 0;
}