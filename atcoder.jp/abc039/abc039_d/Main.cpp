#include <bits/stdc++.h>
using namespace std;

int dr[] = {-1,-1,-1,0,0,1,1,1,0};
int dc[] = {-1,0,1,-1,1,-1,0,1,0};
int main(void){
	int R,C;
	cin >> R >> C;
	vector<string> vs(R);
	vector<string> ans(R),ch;
	for(int i=0;i<R;i++){
		cin >> vs[i];
		for(int j=0;j<C;j++)
			ans[i] += ".";
	}
	ch = ans;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if( vs[i][j] == '.' )continue;
			bool sharp = true;
			for(int k=0;k<8;k++){
				int ii = i + dr[k], jj = j + dc[k];
				if( ii < 0 || jj < 0 || ii >= R || jj >= C )continue;
				if( vs[ii][jj] == '.' )sharp = false;
			}
			if(sharp)ans[i][j] = '#';
		}
	}

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			bool sharp = false;
			for(int k=0;k<9;k++){
				int ii = i + dr[k], jj = j + dc[k];
				if( ii < 0 || jj < 0 || ii >= R || jj >= C )continue;
				if( ans[ii][jj] == '#' )sharp = true;
			}
			if(sharp)ch[i][j] = '#';
		}
	}

	bool ok = true;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if( ch[i][j] != vs[i][j] )ok = false;
		}
	}
	// for(int i=0;i<R;i++)cout << ch[i] << endl;
	if(ok){
		cout << "possible" << endl;
		for(int i=0;i<R;i++){
			cout << ans[i] << endl;
		}
	}else{
		cout << "impossible" << endl;
		// for(int i=0;i<R;i++){
		// 	cout << ans[i] << endl;
		// }
	}
	return 0;
}