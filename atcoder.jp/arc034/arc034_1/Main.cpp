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
	int n;
	cin >> n;
	double ret = 0.;
	for(int i=0;i<n;i++){
		double a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		ret = max(ret,a+b+c+d+e*110/900);
	}
	printf("%.10f\n",ret);
	return 0;
}
