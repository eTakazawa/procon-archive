#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
	}

	int cost = 1e9;
	for(int i=-100;i<=100;i++){
		int tmp = 0;
		for(int j=0;j<N;j++){
			tmp += pow(a[j]-i,2);
		}
		cost = min(cost,tmp);
	}
	cout << cost << endl;
	return 0;
}