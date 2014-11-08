#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
#define N 1000
long long c[N][N];


bool solve(long long n,long long k){
	while(true){
		if(n < k)return true;
		n = n%k;
	}
	return false;
}

long long f(string n){
	long long k = stoi(n);
	long long ret = 0;
	for(int i=0;i<n.size();i++){
		ret *= k;
		ret += n[i] - '0';
	}
	return ret;
}


int main() {
	long long n;
	cin >> n;

	for(int i=10;i<14000;i++){
		if(n==f(to_string(i))){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
