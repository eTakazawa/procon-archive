//写経
//http://arc031.contest.atcoder.jp/submissions/299474

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

template<int V>
struct MaxFlow{
	using T = double;
	const T INF = 1<<28;
	
	struct Edge{
		int to,rev;
		T cap;
	};

	vector<Edge> g[V];
	int level[V];
	int iter[V];

	 void add(int from, int to, T cap) {
        g[from].push_back(Edge{to, (int)g[to].size(), cap});
        g[to].push_back(Edge{from, (int)g[from].size()-1, 0});
    }
    void add_multi(int from, int to, T cap) {
        g[from].push_back(Edge{to, (int)g[to].size(), cap});
        g[to].push_back(Edge{from, (int)g[from].size()-1, cap});
    }

    void bfs(int s){
    	fill_n(level,V,-1);
    	queue<int> que;
    	level[s] = 0;
    	que.push(s);
    	while(!que.empty()){
    		int v = que.front();que.pop();
    		for(Edge e: g[v]){
    			if(e.cap <= 0)continue;
    			if(level[e.to] < 0){
    				level[e.to] = level[v] + 1;
    				que.push(e.to);
    			}
    		}
    	}
    }

    T dfs(int v,int t,T f){
    	if(v == t)return f;
    	for(int &i = iter[v];i < g[v].size();i++){
    		Edge &e = g[v][i];
    		if(e.cap <= 0)continue;
    		if(level[v] < level[e.to]){
    			T d = dfs(e.to,t,min(f,e.cap));
    			if(d <= 0)continue;
    			e.cap -= d;
    			g[e.to][e.rev].cap += d;
    			return d;
    		}
    	}
    	return 0;
    }
    T exec(int s,int t){
    	T flow = 0;
    	while(true){
    		bfs(s);
    		if(level[t] < 0)return flow;
    		fill_n(iter,V,0);
    		T f;
    		while((f = dfs(s,t,INF)) > 0){
    			flow += f;
    		}
    	}
    }

};

int N,M,sum;
vector<vector<int>> A;
vector<int> S,T;
bool solve(double md){
	MaxFlow<300> mf;
	int sv = 298,tv = 297;
	for(int i=0;i<N;i++){
		mf.add(sv,i,S[i]);
	}
	for(int i=0;i<M;i++){
		mf.add(i+110,tv,md*T[i]);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<A[i].size();j++){
			mf.add(i,A[i][j]+110,1e10);
		}
	}
	return mf.exec(sv,tv) < sum;
}


int main(void) {	
	cin >> N >> M;
	S.resize(N);T.resize(M);
	for(int i=0;i<N;i++){
		cin >> S[i];sum += S[i];
	}
	for(int i=0;i<M;i++){
		cin >> T[i];
	}
	A.resize(N);
	for(int i=0;i<N;i++){
		int k;cin >> k;
		for(int j=0;j<k;j++){
			int a;cin >> a;a--;
			A[i].push_back(a);
		}
	}

	double l=0,r=1e9;
	for(int i=0;i<100;i++){
		double md = (l+r)/2;
		if(solve(md)){
			l = md;
		}else{
			r = md;
		}
	}
	cout << fixed << setprecision(10) << l << endl;
	return 0;
}

