#include <bits/stdc++.h>
using namespace std;

int main(void){
	int a,b;
	cin >> a >> b;
	if( a <= 0 && 0 <= b ){
		cout << "Zero" << endl;
	}else{
		if(a>0){
			cout << "Positive" << endl;
		}else{
			if( (b-a+1) % 2 == 0 )cout << "Positive" << endl;
			else cout << "Negative" << endl;
		}
	}

	return 0;
}