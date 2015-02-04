#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long LL;

const double EPS = 1e-8;
const int INF = 1e9;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

string rev(string s){
	reverse(s.begin(),s.end());
	return s;
}

int main(void) {
	string s;
	int n;
	cin >> s >> n;
	for(int i=0;i<n;i++){
		int l,r;
		cin >> l >> r;
		s = s.substr(0,l-1) + rev(s.substr(l-1,r-l+1)) + s.substr(r);
	}
	cout << s << endl;

	return 0;
}

