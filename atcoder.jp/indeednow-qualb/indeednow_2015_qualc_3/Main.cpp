//weekly CD,SRM div2 hard
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> es;
vector<bool>used;
void bfs(){
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(1);
	used[1] = true;
	vector<int> ans;
	while(!pq.empty()){
		int v = pq.top();pq.pop();
		ans.push_back(v);
		for(int i=0;i<es[v].size();i++){
			int u = es[v][i];
			if(used[u])continue;
			pq.push(u);
			used[u] = true;
		}

	}
	for(int i=0;i<ans.size();i++){
		cout << ans[i];
		if(i != ans.size()-1)cout << " ";
	}
	cout << endl;
}

int main(void) {
	int n;
	cin >> n;
	vector<int>a(n),b(n);
	es.resize(n+1);
	used.resize(n+1);
	for(int i=0;i<n-1;i++){
		cin >> a[i] >> b[i];
		es[a[i]].push_back(b[i]);
		es[b[i]].push_back(a[i]);
	}
	bfs();


	return 0;
}

