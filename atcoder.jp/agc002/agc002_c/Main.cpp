#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,L;
	cin >> N >> L;
	vector<long long> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
	}

	int ret = -1;
	for(int i=0;i<N;i++){
		if(a[i] >= L)ret = i;
		if(i != N-1 && a[i]+a[i+1] >= L)ret = i;
	}
	if(ret != -1){
		cout << "Possible" << endl;
		for(int i=0;i<ret;i++)
			cout << i+1 << endl;
		for(int i=N-1;i>ret;i--){
			cout << i << endl;
		}
	}
	else cout << "Impossible" << endl;

	return 0;
}