#include <bits/stdc++.h>
#define INF INT_MAX / 2
#define MOD 1000000007

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int>> PIPII;
typedef long long ll;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(void) {
	int n;
	cin >> n;
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += i+1;
	}
	cout << ans << endl;
	return 0;
}

