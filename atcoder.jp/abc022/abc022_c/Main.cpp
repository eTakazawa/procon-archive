#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(void){
	int n,m;
	cin >> n >> m;
	vector<vector<ll>> dist(n,vector<ll>(n,5e9));
	set<int> sv;
	vector<ll> sd(n);
	for(int i=0;i<m;i++){
		int u,v,l;
		cin >> u >> v >> l;
		u--;v--;
		if(u == 0){
			sv.insert(v);
			sd[v] = l;
		}
		else if(v == 0){
			sv.insert(u);
			sd[u] = l;
		}
		else{
			dist[u][v] = l;
			dist[v][u] = l;
		}

	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	vector<int> s(sv.begin(),sv.end());
	ll ret = 5e9;
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			ret = min(ret,dist[s[i]][s[j]]+sd[s[i]]+sd[s[j]]);
		}
	}
	cout << (ret>=5e9?-1:ret) << endl;
}