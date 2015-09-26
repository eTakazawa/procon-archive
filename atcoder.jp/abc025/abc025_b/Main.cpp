#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,a,b;
	cin >> n >> a >> b;
	int c = 0;
	for(int i=0;i<n;i++){
		string s;int d;
		cin >> s >> d;
		if(d < a)d = a;
		else if(d > b)d = b;

		if(s == "East"){
			c += d;
		}else{
			c -= d;
		}
	}

	if(c == 0){
		cout << 0 << endl;
	}else if(c < 0){
		cout << "West " << -c << endl;
	}else{
		cout << "East " << c << endl;
	}

	return 0;
}