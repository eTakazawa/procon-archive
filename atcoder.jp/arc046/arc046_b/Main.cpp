#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n,A,B;	
	cin >> n;
	cin >> A >> B;

	if(n <= A){
		cout << "Takahashi" << endl;
			return 0;
	}
	if(n-1 <= B){
		cout << "Aoki" << endl;
			return 0;
	}
	if(A == B){
		if(n % (A+1) != 0)cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
		return 0;
	}
	if(A > B)cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;


	return 0;
}