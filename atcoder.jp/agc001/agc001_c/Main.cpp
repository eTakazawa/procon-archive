#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> es;
int bfs(int start,int k,int stop=-1){
	queue<int> que,dist;
	set<int> st;
	que.push(start);dist.push(0);
	while(!que.empty()){
		int v = que.front();que.pop();
		int d = dist.front();dist.pop();
		st.insert(v);
		for(int i=0;i<es[v].size();i++){
			if(st.find(es[v][i]) != st.end())continue;
			if( es[v][i] == stop )continue;
			if( d + 1 > k)continue;
			st.insert(es[v][i]);
			que.push( es[v][i] );
			dist.push(d + 1);
		}
	}
	return st.size();
}

int main(void){
	int N,K;
	cin >> N >> K;
	es.resize(N);
	vector<pair<int,int>> e;
	for(int i=0;i<N-1;i++){
		int a,b;cin >> a >> b;a--;b--;
		es[a].push_back(b);
		es[b].push_back(a);
		e.emplace_back(a,b);
	}

	int ret = -1;
	if(K%2 == 0){
		// 中心の頂点を決める
		for(int i=0;i<N;i++){
			ret = max( ret, bfs(i,K/2));
		}
	}else{
		for(int i=0;i<N-1;i++){
			int nodes = bfs( e[i].first, K/2, e[i].second ) + bfs( e[i].second, K/2, e[i].first );
			ret = max( ret, nodes);
		}
	}
	cout << N-ret << endl;
}