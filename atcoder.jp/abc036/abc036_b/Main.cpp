#include <bits/stdc++.h>
using namespace std;


int main(void){
	int N;
	cin >> N;
	vector<string> vs(N);
	for(int i=0;i<N;i++){
		cin >> vs[i];
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << vs[N-1-j][i];
		}
		cout << endl;
	}
	return 0;
}