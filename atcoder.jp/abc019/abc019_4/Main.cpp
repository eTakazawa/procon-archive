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
	int N;
	cin >> N;
	int d1=0,d2=0;
	int to;
	for(int i=2;i<=N;i++){
		int d;
		cout << "? " << 1 << " " << i << endl;
		cin >> d;
		if(d > d1){
			d1 = d;
			to = i;
		}
	}
	for(int i=1;i<=N;i++){
		if(to == i)continue;
		int d;
		cout << "? " << to << " " << i << endl;
		cin >> d;
		d2 = max(d2,d);
	}
	cout << "! " << d2 << endl;

	return 0;
}