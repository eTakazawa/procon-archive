#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

ll bfs(int a,int b,vector<vector<int>>& es){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(pair<int,int>(0,a));
	
	vector<ll> cnt(es.size());
	vector<int> dist(es.size(),1e9);
	dist[a] = 0;cnt[a] = 1;
	while(!pq.empty()){
		pair<int,int> p = pq.top();pq.pop();
		int d = p.first,v = p.second;
		for(int i=0;i<es[v].size();i++){
			int u = es[v][i];
			if(dist[u] == d + 1){
				cnt[u] += cnt[v];
				cnt[u] %= MOD;
			}
			if(dist[u] > d + 1){
				dist[u] = d + 1;
				cnt[u] += cnt[v];
				cnt[u] %= MOD;
				pq.push(pair<int,int>(d+1,u));
			}
		}
	}
	return cnt[b]%MOD;
}

int main(void) {
	int n,a,b;
	cin >> n >> a >> b;a--;b--;
	int m;
	cin >> m;
	vector<vector<int>> es(n);
	for(int i=0;i<m;i++){
		int x,y;cin >> x >> y;
		x--;y--;
		es[x].push_back(y);
		es[y].push_back(x);
	}
	cout << bfs(a,b,es) << endl;
	return 0;
}
