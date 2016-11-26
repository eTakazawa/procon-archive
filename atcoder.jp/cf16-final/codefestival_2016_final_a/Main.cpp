#include <bits/stdc++.h>
using namespace std;

int main(void){
	int H,W;
	cin >> H >> W;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			string s;
			cin >> s;
			if( s == "snuke" ){
				cout << (char)(j + 'A');
				cout << i+1 << endl;
			}
		}
	}

	return 0;
}