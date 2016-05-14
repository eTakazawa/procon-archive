#include <bits/stdc++.h>
using namespace std;

int main(void){
	int H,W;
	cin >> H >> W;
	int ret = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(j == W-1 || i == H-1)ret += 1;
			else ret += 2;
		}
	}
	cout << ret-1 << endl;
	return 0;
}