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

int main(void) {
	vector<int> a(3);
	for(int i=0;i<3;i++)cin >> a[i];
	vector<int> b(a);
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(b[i] == a[j]){
				cout << j+1 << endl;
				break;
			}
		}
	}
	

	return 0;
}
