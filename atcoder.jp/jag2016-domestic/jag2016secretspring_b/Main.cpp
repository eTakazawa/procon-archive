#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,M,T;
	cin >> N >> M >> T;

	vector<int> a;
	a.push_back(0);
	for(int i=0;i<N;i++){
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	a.push_back(T);

	int ret = 0;
	for(int i=0;i<N+1;i++){
		if(i == 0 || i == N)ret += max(0, (a[i+1] - a[i]) - M);
		else ret += max(0, (a[i+1] - a[i]) - 2 * M);
	}
	cout << ret << endl;
	return 0;
}