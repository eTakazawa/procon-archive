#include <bits/stdc++.h>
using namespace std;
//素数判定
bool is_prime(int n) {
	for(int i=2; i*i <= n; i++) {
		if(n%i == 0)return false;
	}
	return n != 1;
}

int main(void){
	vector<int> a;
	for(int i=2;i<10000;i++){
		if( is_prime(i) ){
			a.push_back(i);
		}
	}
	int M = a.size();

	vector<int> cnt(M,1);
	srand(0);
	for(int i=0;i<100;i++){
		long long n = 1;
		for(;;){
			int id = rand() % M;
			if( pow(a[id], cnt[id]) > 1000000 )continue;
			if( n * pow(a[id], cnt[id]) > 1000000000)break;
			n *= pow(a[id], cnt[id]);
			cnt[id]++;
		}
		cout << n << endl;
	}
	

	return 0;
}