#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,Q;
	cin >> N >> Q;
	vector<int> vec(N+2);

	for(int i=0;i<Q;i++){
		int l,r;
		cin >> l >> r;
		l--;r--;
		vec[l]++;
		vec[r+1]--;
	}

	for(int i=0;i<=N;i++){
		vec[i+1] += vec[i];
	}

	for(int i=0;i<N;i++){
		cout << vec[i]%2;
	}cout << endl;

	return 0;
}