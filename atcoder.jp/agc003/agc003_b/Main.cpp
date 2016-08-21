#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	long long cnt = 0;
	for(int i=0;i<N;i++){
		cnt += A[i] / 2;
		A[i] %= 2;
		if(A[i] == 1 && i != N-1 && A[i+1] > 0){
			cnt++;
			A[i+1]--;
		}
	}
	cout << cnt << endl;
	return 0;
}