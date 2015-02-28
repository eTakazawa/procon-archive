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
	vector<int> a(3);
	for(int i=0;i<3;i++)cin >> a[i];
	sort(a.begin(),a.end());
	cout << a[1] << endl;
	return 0;
}