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

int main(void) {
	int N;
	cin >> N;
	string s = "indeednow";
	sort(begin(s),end(s));
	for(int i=0;i<N;i++){
		string t;
		cin >> t;
		sort(t.begin(),t.end());
		if(t == s)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
