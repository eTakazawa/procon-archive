#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> L(2*N);
	for(int i=0;i<2*N;i++){
		cin >> L[i];
	}
	sort(L.begin(),L.end());
	int ret = 0;
	for(int i=0;i<2*N;i+=2){
		ret += L[i];
	}
	cout << ret << endl;
	return 0;
}