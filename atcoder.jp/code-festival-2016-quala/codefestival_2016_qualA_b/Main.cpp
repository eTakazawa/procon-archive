#include <bits/stdc++.h>
using namespace std;


int main(void){
	int N;
	cin >> N;
	vector<int> a(N+1,N);

	int cnt = 0;
	for(int i=0;i<N;i++){
		cin >> a[i];
		a[i]--;
		if( a[a[i]] == i )cnt++;
	}

	cout << cnt << endl;


	return 0;
}
