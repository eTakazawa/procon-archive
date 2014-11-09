#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include<algorithm>
#include <utility>
#include <climits>
using namespace std;
#define INF LONG_MAX
#define MAX_V 1010
#define ll long long

typedef pair<ll,ll>P;		//firstは最短距離、secondは頂点の番号

struct edge{
	edge(int to,int cost):to(to),cost(cost){}
	ll to,cost;
};

int V;
vector<edge>G[MAX_V];
long long d[MAX_V];

//O(ElogV)
void dijkstra(int s){
	//greater<P>を指定することでfirstが小さい順に取り出せるようにする。
	priority_queue<P,vector<P>,greater<P> >que;
	fill(d,d+V,INF);
	d[s] = 0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v = p.second;
		if(d[v] < p.first)continue;
		for(int i=0;i<G[v].size();i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

int main() {
	int n,m;
	int s,t;
	cin >> n >> m;
	V=n;
	cin >> s >> t;
	s--;t--;

	for(int i=0;i<m;i++){
		int a,b,d;
		cin >> a >> b >> d;
		--a;--b;
		G[a].push_back(edge(b,d));
		G[b].push_back(edge(a,d));
	}

	dijkstra(s);
	long long sd[MAX_V];

	for(int i=0;i<n;i++){
		sd[i] = d[i];
	}
	for(int i=0;i<n;i++){
		if(sd[i]==INF|| i==s || i==t)continue;
		dijkstra(i);
		if(sd[i] == d[t] ){
			cout << i+1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}
