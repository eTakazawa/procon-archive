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
	int cnt = 1;
	string t;
	for(int i=1;i<s.size();i++){
		if(s[i] == s[i-1]){
			cnt++;
		}else{
			t += s[i-1];
			t += to_string(cnt);
			cnt = 1;
		}
		if(i == s.size()-1){
			t += s[i];
			t += to_string(cnt);
		}
	}
	cout << t << endl;
}