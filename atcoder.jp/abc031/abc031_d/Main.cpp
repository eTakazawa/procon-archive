#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<string> v;
vector<string> w;
int N,K;

vector<string> ret;
void dfs(int n){
	if(n == K){
		bool f = true;
		vector<string> ans(K);

		for(int i=0;i<N;i++){
			int l = 0;
			for(int j=0;j<v[i].size();j++){
				int t = p[v[i][j]-'1'];

				if(w[i].size() < t+l){
					f = false;
					break;
				}

				if(ans[v[i][j]-'1'] == ""){
					ans[v[i][j]-'1'] = w[i].substr(l,t); 
				}
				else{
					if( ans[v[i][j]-'1'] != w[i].substr(l,t)){
						f = false;
						break;
					}
				}
				l += t;
			}
			if(w[i].size() != l)f = false;
			if(!f)break;
		}
		if(f){
			ret = ans;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		p.push_back(i);
		dfs(n+1);
		p.pop_back();
	}
}

int main(void){
	cin >> K >> N;
	v.resize(N);w.resize(N);
	for(int i=0;i<N;i++){
		cin >> v[i] >> w[i];
	}
	// string a = "abcd";
	// cout << a.substr(,2) << endl;
	dfs(0);
	for(int i=0;i<K;i++){
		cout << ret[i] << endl;
	}
	return 0;
}