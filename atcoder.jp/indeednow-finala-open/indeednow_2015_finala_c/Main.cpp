#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
const int INF = 1e9;

int main(void) {
	int n,m;
	cin >> n >> m;
	vector<int>a(n),b(n),c(n),w(n);
	vector<vector<vector<int>>> cub(101,vector<vector<int>>(101,vector<int>(101)));
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i] >> c[i] >> w[i];
		cub[a[i]][b[i]][c[i]] = max(cub[a[i]][b[i]][c[i]],w[i]);
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			for(int k=0;k<100;k++){
				cub[i][j][k+1] = max(cub[i][j][k],cub[i][j][k+1]);
			}
		}
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			for(int k=0;k<100;k++){
				cub[i][k+1][j] = max(cub[i][k][j],cub[i][k+1][j]);
			}
		}
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			for(int k=0;k<100;k++){
				cub[k+1][i][j] = max(cub[k][i][j],cub[k+1][i][j]);
			}
		}
	}

	vector<int> x(m),y(m),z(m);
	for(int i=0;i<m;i++){
		cin >> x[i] >> y[i] >> z[i];
	}

	for(int i=0;i<m;i++){
		cout << cub[x[i]][y[i]][z[i]] << endl;
	}
	return 0;
}