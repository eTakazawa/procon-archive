#include <bits/stdc++.h>
using namespace std;

map<int,int> res;
void prime_factor(int n){
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			++res[i];
			n /= i;
		}
	}
	if(n!=1)res[n]++;
}

int main(void){
	int N;
	cin >> N;

	for(int i=1;i<=N;i++){
		prime_factor(i);
	}

	long long ret = 1;
	for(auto it=res.begin();it!=res.end();it++){
		// cerr << it->second << endl;
		ret *= (it->second + 1);
		ret %= 1000000007L;
	}
	cout << ret << endl;
	return 0;
}

// 2,3,4,5,6
// 4,3,1