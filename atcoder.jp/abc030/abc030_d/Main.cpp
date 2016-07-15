#include <bits/stdc++.h>
using namespace std;

vector<int> e;
vector<int> vis;

int T;
int cyc(int v,int cnt){
	if(vis[v] != -1){
		T = vis[v];
		return cnt - vis[v];
	}
	vis[v] = cnt;
	return cyc(e[v],cnt+1);
}

int sim(int v,int cnt,int ed){
	if(cnt == ed)return v;
	return sim(e[v],cnt+1,ed);
}

int main(void){
	int N,a;
	string k;
	cin >> N >> a >> k;
	a--;

	vector<int> b(N);
	e.resize(N);
	vis.resize(N,-1);
	for(int i=0;i<N;i++){
		cin >> b[i];
		b[i]--;
		e[i] = b[i];
	}

	int cycLen = cyc(a,0);
	if(k.size() < 8){
		cout << sim(a,0,stoll(k))+1 << endl;
	}else{
		int k_mod_C = 0;
		for(int i=0;i<k.size();i++){
			k_mod_C = (k_mod_C*10 + k[i] - '0') % cycLen;
		}
		while(k_mod_C < T)k_mod_C += cycLen;
		// cout << k_mod_C << endl;
		cout << sim(a,0,k_mod_C)+1 << endl;
	}

	return 0;
}