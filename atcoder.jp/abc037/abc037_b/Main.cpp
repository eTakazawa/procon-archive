#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,Q;
	cin >> N >> Q;
	vector<int> a(N+1);
	for(int i=0;i<Q;i++){
		int L,R,T;
		cin >> L >> R >> T;
		for(int j=L;j<=R;j++){
			a[j] = T;
		}
	}
	for(int i=1;i<=N;i++){
		cout << a[i] << endl;
	}
	return 0;
}