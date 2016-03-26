#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> P;
struct Edge{
	int to;int cost;
};
vector<long long> dist;
vector<long long> to0;
vector<int> A;
vector<vector<Edge>> es;
vector<vector<Edge>> rev;

void dijkstra(){
	priority_queue<pair<long long,int>,vector<P>,greater<P>> pq;
	pq.push(make_pair(0,0));
	dist = vector<long long>(A.size(),1e12/2LL);
	dist[0] = 0;
	while(!pq.empty()){
		pair<long long,int> p = pq.top();pq.pop();
		int v = p.second;
		for(int i=0;i<es[v].size();i++){
			int w = es[v][i].to;
			int cost = es[v][i].cost;
			if( dist[w] <= dist[v] + cost )continue;
			dist[w] = dist[v] + cost;
			pq.push(make_pair(dist[w], w));
		}
	}
}

void dijkstra2(){
	priority_queue<pair<long long,int>,vector<P>,greater<P>> pq;
	pq.push(make_pair(0,0));
	to0 = vector<long long>(A.size(),1e12/2LL);
	to0[0] = 0;
	while(!pq.empty()){
		pair<long long,int> p = pq.top();pq.pop();
		int v = p.second;
		for(int i=0;i<rev[v].size();i++){
			int w = rev[v][i].to;
			int cost = rev[v][i].cost;
			if( to0[w] <= to0[v] + cost )continue;
			to0[w] = to0[v] + cost;
			pq.push(make_pair(to0[w], w));
		}
	}
}

int main(void){
	int N,M,T;
	cin >> N >> M >> T;
	A = vector<int>(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	es = vector<vector<Edge>>(N);
	rev = vector<vector<Edge>>(N);
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		es[a].push_back(Edge{b,c});
		rev[b].push_back(Edge{a,c});
	}

	dijkstra();
	dijkstra2();

	// for(int i=0;i<N;i++){
	// 	cout << dist[i] << " ";
	// }cout << endl;

	long long ret = 0;
	for(int i=0;i<N;i++){
		if(dist[i]+to0[i] >= T)continue;
		long long tmp = (T-dist[i]-to0[i]) * A[i];
		ret = max(tmp, ret);
	}
	cout << ret << endl;

	return 0;
}