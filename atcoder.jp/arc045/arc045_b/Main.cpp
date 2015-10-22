#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;
	vector<int> s(m),t(m);
	vector<vector<int>> vs(n+1),vt(n+1);
	vector<int> rooms(n+1);
	for(int i=0;i<m;i++){
		cin >> s[i] >> t[i];
		s[i]--;t[i]--;
		vs[s[i]].push_back(i);
		vt[t[i]].push_back(i);
		rooms[s[i]] += 1;
		rooms[t[i]+1] -= 1;
	}

	for(int i=0;i<n;i++){
		rooms[i+1] += rooms[i];
	}

	set<int> pre,ret;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<vs[i].size();j++){
			pre.insert(vs[i][j]);
		}
		if( rooms[i] < 2 )pre.clear();

		for(int j=0;j<vt[i].size();j++){
			if( pre.find(vt[i][j]) != pre.end() ){
				ret.insert(vt[i][j]);
			}
		}
	}
	auto it = ret.begin();
	cout << ret.size() << endl;
	for(;it!=ret.end();it++){
		cout << (*it)+1 << endl;
	}

	return 0;
}