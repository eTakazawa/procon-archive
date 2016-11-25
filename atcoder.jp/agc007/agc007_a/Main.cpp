#include <bits/stdc++.h>
using namespace std;

int used[10][10];
int main(void){
	int H,W;
	cin >> H >> W;
	vector<string> a(H);
	for(int i=0;i<H;i++){
		cin >> a[i];
	}

	if(a[H-1][W-1] == '.'){
		cout << "Impossible" << endl;
		return 0;
	}

	bool ok = true;
	int y,x;
	y = x = 0;
	while( y != H-1 || x != W-1 ){
		a[y][x] = '.';
		if(y+1 < H && a[y+1][x] == '#'){
			y++;
			a[y][x] = '.';
		}
		else if(x+1 < W && a[y][x+1] == '#'){
			x++;
			a[y][x] = '.';
		}
		else{
			ok = false;
			break;
		}
	}

	for(int i=0;i<H;i++){
		// cerr << a[i] << endl;
		for(int j=0;j<W;j++){
			if(a[i][j] == '#')ok = false;
		}
	}
	if(ok)cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}