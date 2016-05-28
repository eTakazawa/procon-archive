#include <bits/stdc++.h>
using namespace std;
 
int main(void){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
 
	vector<int> cnt(N,1);
	for(int i=1;i<N;i++){
		if(a[i] > a[i-1]){
			cnt[i] = cnt[i-1] + 1;
		}
	}
	long long ret = 0;
	for(int i=0;i<N;i++){
		ret += cnt[i];
	}
	cout << ret << endl;
	return 0;
}