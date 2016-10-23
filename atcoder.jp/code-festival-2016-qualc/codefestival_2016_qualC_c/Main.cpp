#include <bits/stdc++.h>
using namespace std;
 
int main(void){
	int N;
	const int MOD = 1e9+7;
	cin >> N;
	vector<long long> A(N),T(N);
	vector<long long> AA(N),TT(N);
	for(int i=0;i<N;i++){
		cin >> T[i];
	}
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
 
	AA[N-1] = A[N-1];
	TT[0] = T[0];
	for(int i=0;i<N-1;i++){
		if(T[i] != T[i+1])TT[i+1] = T[i+1];
	}
	for(int i=N-1;i>0;i--){
		if(A[i] != A[i-1])AA[i-1] = A[i-1];
	}
 
	bool ok = true;
	for(int i=0;i<N;i++){
		if(AA[i] != 0){
			if( T[i] < AA[i] )ok =false;
		}
		if(TT[i] != 0){
			if( A[i] < TT[i])ok = false;
		}
		if(AA[i] != 0 && TT[i] != 0 && AA[i] != TT[i])ok = false;
		// cerr << AA[i] << " ";
	}
	// cerr << endl;
 
	if(!ok){
		cout << 0 << endl;
		return 0;
	}
 
	long long ret = 1;
	for(int i=0;i<N-2;i++){
		if( T[i] == T[i+1] && A[i+1] == A[i+2]){
			ret *= min(T[i+1],A[i+1]);
			ret %= MOD;
			// cerr << min(T[i],A[i]) << " ";
		}
	}
 
	if( T[N-1] != A[0] )cout << 0 << endl;
	else cout << ret << endl;
	return 0;
}