#include <bits/stdc++.h>
using namespace std;

int main(void){
	int H,W,H2,W2;
	cin >> H >> W>> H2 >> W2;
	if(H == H2 || W == H2 || W2 == H || W2 == W)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}