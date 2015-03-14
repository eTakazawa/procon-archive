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
	vector<int> s(N);
	vector<int> v(1000001);
	for(int i=0;i<N;i++){
		cin >> s[i];
		if(s[i] != 0)
			v[s[i]]++;
	}
	for(int i=1000000;i>0;i--){
		v[i-1] += v[i];
	}
	for(int i=0;i<1000001;i++){
		v[i] = -v[i];
	}

	int Q;
	cin >> Q;
	vector<int> k(Q);
	for(int i=0;i<Q;i++)
		cin >> k[i];

	for(int i=0;i<Q;i++){
		cout << lower_bound(v.begin(), v.end(),-k[i])-v.begin() << endl;
	}

	return 0;
}

