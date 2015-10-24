#include <bits/stdc++.h>
using namespace std;

int main(void){
	int t;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		int n;cin >> n;
		vector<vector<long long>> d(n,vector<long long>(n));
		vector<vector<long long>> d2(n,vector<long long>(n));
		bool f = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int a;cin >> a;
				if(i == j){
					if(a != 0)f = false;
					continue;
				}
				if(a == -1)
					d[i][j] = 1e9;
				else
					d[i][j] = a;
			}
		}
		d2 = d;
		for(int w=0;w<n;w++){
			for(int u=0;u<n;u++){
				for(int v=0;v<n;v++){
					d[u][v] = min(d[u][v], d[u][w]+d[w][v]);
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				// cout << d[i][j] << " ";
				if(d2[i][j] != d[i][j])
					f = false;
			}
			// cout << endl;
		}
		cout << (f? "YES" : "NO") << endl;
	}
	return 0;
}