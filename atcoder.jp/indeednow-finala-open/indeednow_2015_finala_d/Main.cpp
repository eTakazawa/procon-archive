#include <bits/stdc++.h>
using namespace std;


int ret;
vector<vector<pair<int,int>>> es;
vector<int> in,out;
void dfs(int p,int prev){
	int n = es[p].size();
	// cout << p << endl;
	for(int i=0;i<n;i++){
		if(es[p][i].first == prev)continue;
		dfs(es[p][i].first,p);
	}
	
	out[p] = in[p] = 1;
	vector<int> max_in_l(n+1),max_out_l(n+1);
	vector<int> max_in_r(n+1),max_out_r(n+1);
	for(int i=0;i<n;i++){
		int x = es[p][i].first;
		int t = es[p][i].second;
		if(prev == x)continue;
		if(t==2 || t==1){
			max_out_r[i] = max_out_l[i] = out[x];
			out[p] = max(out[x]+1, out[p]);
		}
		if(t==2 || t==0){
			max_in_r[i] = max_in_l[i] = in[x];
			in[p] = max(in[x]+1, in[p]);
		}
	}

	for(int i=0;i<n;i++){
		max_out_l[i+1] = max(max_out_l[i+1], max_out_l[i]);
		max_in_l[i+1] = max(max_in_l[i+1], max_in_l[i]);
		max_in_r[n-i-1] = max(max_in_r[n-i-1], max_in_r[n-i]);
		max_out_r[n-i-1] = max(max_out_r[n-i-1], max_out_r[n-i]);
	}

	ret = max(ret, max_out_r[0]);
	ret = max(ret, max_in_r[0]);
	for(int i=0;i<n-1;i++){
		ret = max(ret,max_out_l[i] + max_in_r[i+1]);
		ret = max(ret,max_in_l[i] + max_out_r[i+1]);
	}
}

int main(void){
	int n;
	cin >> n;
	es = vector<vector<pair<int,int>>>(n+1);

	in = vector<int>(n+1);
	out = vector<int>(n+1);
	for(int i=0;i<n-1;i++){
		int a,b,t;
		cin >> a >> b >> t;
		a--;b--;
		if(t == 2){
			es[a].push_back(make_pair(b,2));
			es[b].push_back(make_pair(a,2));
		}else{
			es[a].push_back(make_pair(b,1));
			es[b].push_back(make_pair(a,0));
		}
	}

	dfs(0,-1);
	for(int i=0;i<n;i++){
		// cout << i << " " << out[i] << " " << in[i] << endl;
	}
	cout << ret-1 << endl;

	return 0;
}