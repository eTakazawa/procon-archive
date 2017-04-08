#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<vector<int>> cnt(n,vector<int>(26));
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			cnt[i][s[j] - 'a']++;
		}
	}

	vector<int> res(26);
	for(int j=0;j<26;j++){
		res[j] = 100;
		for(int i=0;i<n;i++){
			res[j] = min(res[j], cnt[i][j]);
		}
	}
	for(int i=0;i<26;i++){
		string s(res[i],'a'+i);
		cout << s;
	}
	cout << endl;
	return 0;
}