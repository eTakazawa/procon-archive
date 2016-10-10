#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> A(N);

	bool isTwo = false;
	for(int i=0;i<N;i++){
		cin >> A[i];
		if(A[i] == 2 && i != 0)isTwo = true;
	}

	
	long long ret = 0, p = 1;
	for(int i=0;i<N;i++){
		if( A[i] > p ){
			if( p == 1 ){
				ret += A[i] - 1;
				p++;
			}else if( A[i] % p == 0 ){
				A[i] -= ( p + 1 );
				ret += 1 + A[i] / p;
			}else{
				ret += A[i] / p;
			}
		}else if( A[i] == p )p++;
	}

	cout << ret << endl;
	return 0;
}