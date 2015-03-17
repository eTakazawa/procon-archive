//ドワンゴ　フィッシング　8020
//SYAKYO http://dwango2015-honsen.contest.atcoder.jp/submissions/337993
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

const int MAX_V = 400;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
int V;
void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
bool dfs(int v){
	used[v] = true;
	for(int i=0;i<G[v].size();i++){
		int u = G[v][i],w = match[u];
		if(w < 0 || (!used[w] && dfs(w))){
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int nibu(){
	int res = 0;
	memset(match,-1,sizeof(match));
	for(int v=0;v<V;v++){
		if(match[v] < 0){
			memset(used,0,sizeof(used));
			if(dfs(v))res++;
		}
	}
	return res;
}
int N;
string s[200];
vector<int> nums;
bool solve(){
	int N;
	cin >> N;
	V = 2*N;
	for(int i=0;i<N;i++){
		cin >> s[i];
	}
	for(int i=0;i<N;i++)nums.push_back(s[i].size());
	sort(begin(nums),end(nums));

	int mn = 1e9;
	for(int i=0;i<N;i++)mn = min(mn,nums[i]-i);

	for(int c=0;c<26;c++){
		for(int i=0;i<mn;){
			for(int j=0;j<V;j++)G[j].clear();

			for(int j=0;j<N;j++)for(int k=0;k<N;k++){
				if(s[j].size() > k+i && s[j][k+i] == 'a' + c)add_edge(j,k+N);
			}
			int a = nibu();
			if(a == N)return true;
			//足りない分ずらす
			i += N - a;
		}
	}
	return false;
}
int main(void) {	
	if(solve()) puts("YES");
	else puts("NO");
	return 0;
}

