#include <bits/stdc++.h>
using namespace std;

int main(void){
	long long N;
	cin >> N;
	int d = 0;
	for(long long n=N;n>0;n/=2)
		d++;

	long long x = 1;
	if(d%2==1){
		for(;;){
			x <<= 1;
			x += 1;
			if(x > N){
				cout << "Aoki" << endl;
				break;
			}
			x <<= 1;
			if(x > N){
				cout << "Takahashi" << endl;
				break;
			}
		}
	}else{
		for(;;){
			x <<= 1;
			if(x > N){
				cout << "Aoki" << endl;
				break;
			}
			x <<= 1;
			x += 1;
			if(x > N){
				cout << "Takahashi" << endl;
				break;
			}
		}
	}

	return 0;
}