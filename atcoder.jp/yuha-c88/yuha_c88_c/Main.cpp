#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	map<string,int> dict;
	vector<string> player(n);
	for(int i=0;i<n;i++){
		string s;cin >> s;
		dict[s] = i;
		player[i] = s;
	}

	vector<vector<int>> hatugen(n,vector<int>(2));
	for(int i=0;i<n;i++){
		string u,a,b,v,vv;
		cin >> u >> a >> b >> v >> vv;
		if(v == "good"){
			hatugen[i][0] = dict[u];
			hatugen[i][1] = 1;
		}else{
			hatugen[i][0] = dict[u];
			hatugen[i][1] = -1;
		}
	}
	
	
	int maxans = 0;
	vector<string> ans;

	for(int p=0;p<(1<<n);p++){
		int cnt = 0;
		bool ok = true;
		vector<string> tmp;
		vector<int> hantei(n);//0,1,-1: 未決定,true,false
		for(int i=0;i<n;i++){
			if(p & (1<<i)){
				hantei[i] = 1;
				tmp.push_back(player[i]);
				cnt++;
			}else{
				hantei[i] = -1;
			}
		}
		for(int i=0;i<n;i++){
			int to = hatugen[i][0];
			int say = hatugen[i][1];
			if(hantei[i] == 1){
				if(hantei[to] != say){
					ok = false;
				}
			}else{
				if(hantei[to] == say){
					ok = false;
				}
			}
		}

		if(ok == false)continue;
		sort(tmp.begin(),tmp.end());
		if(cnt > maxans){
			ans = tmp;
			maxans = cnt;
		}else if(cnt == maxans){
			for(int i=0;i<ans.size();i++){
				if(ans[i] > tmp[i]){
					ans = tmp;
					maxans = cnt;
					break;
				}
			}
		}
	}

	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	if(ans.size() == 0){
		cout << "No answers" << endl;
	}
    return 0;
}