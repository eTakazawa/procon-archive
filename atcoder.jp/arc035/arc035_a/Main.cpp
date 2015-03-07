#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-8;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main(void) {
	string s;
	cin >> s;

	string ss = s;
	reverse(s.begin(),s.end());

	bool yes = true;
	for(int i=0;i<s.size();i++){
		if(ss[i] != s[i] && s[i] != '*' && ss[i] != '*')yes = false;
	}
	if(yes)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
