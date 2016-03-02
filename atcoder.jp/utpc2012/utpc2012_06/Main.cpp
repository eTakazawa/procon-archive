#include <bits/stdc++.h>
using namespace std;


int main(void){
	int a,b;
	map<long long, vector<string>> mp;
	vector<int> hashs;
	cin >> a >> b;

	while(hashs.size() < 7){
		string haiku;long long h = 0;
		for(int i=0;i<7;i++){
			int n = rand()%26;
			haiku += 'a' + n;
			h = (h * a + n + 1) % b;
		}
		if( mp[h].size() == 0 )mp[h].push_back(haiku);
		if( mp[h].size() == 1 && mp[h][0] != haiku ){
			mp[h].push_back(haiku);
			hashs.push_back(h);
		}	
	}

	for(int i=0;i<100;i++){
		string ans;
		for(int j=0;j<7;j++){
			ans += mp[hashs[j]][(i>>j)&1];
		}
		cout << ans << endl;
	}

	return 0;
}