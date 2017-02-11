#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,M;
	cin >> N >> M;
	vector<string> A(N),B(M);
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<M;i++)
		cin >> B[i];

	for(int i=0;i<N-M+1;i++){
		for(int j=0;j<N-M+1;j++){
			bool ch = true;
			for(int y=0;y<M;y++){
				for(int x=0;x<M;x++){
					if( A[i+y][j+x] != B[y][x] )ch = false;
				}
			}
			if(ch){
				cout << "Yes" << endl;
				exit(0);
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
