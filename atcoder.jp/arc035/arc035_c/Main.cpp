#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-8;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main(void) {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> dist(n,vector<int>(n,INF));
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}

	int k;
	cin >> k;
	for(int l=0;l<k;l++){
		int x,y,z;
		cin >> x >> y >> z;
		x--;y--;
		if(dist[x][y] > z){
			dist[y][x] = dist[x][y] = z;
			for(int l=0;l<n;l++){
				for(int m=0;m<n;m++){
					dist[l][m] = min(dist[l][m], dist[l][x] + dist[x][m]);
				}
			}
			for(int l=0;l<n;l++){
				for(int m=0;m<n;m++){
					dist[l][m] = min(dist[l][m], dist[l][y] + dist[y][m]);
				}
			}
		}

		ll d = 0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				//cout << i << " " << j << " " << dist[i][j] << endl;
				d += dist[i][j];
			}
		}
		cout << d << endl;
	}
}
