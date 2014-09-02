#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int ans[2501];
int main(void) {
	int N,d[50][50],Q,p[2500];
	cin >> N;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> d[i][j];
	cin >> Q;
	for (int i = 0; i < Q; ++i)
		cin >> p[i];
	
	for(int i=0;i<N;i++)
		for (int j = 0; j < N-1; ++j)
			d[i][j+1] += d[i][j];
	for(int i=0;i<N-1;i++)
		for (int j = 0; j < N; ++j)
			d[i+1][j] += d[i][j];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; ++j) {
			for (int k = i; k < N; ++k) {
				for (int l = j; l < N; ++l) {
					int good = 0;
					good = d[k][l] - (i == 0 ? 0 : d[i - 1][l])
							- (j == 0 ? 0 : d[k][j - 1])
							+ ((i == 0 || j == 0) ? 0 : d[i - 1][j - 1]);
					ans[(k-i+1)*(l-j+1)] = max(ans[(k-i+1)*(l-j+1)], good);
				}
			}
		}
	}

	for (int i = 0; i < Q; ++i) {
		int ret = 0;
		for (int j = 0; j <= p[i]; ++j) {
			ret = max(ret,ans[j]);
		}
		cout << ret << endl;
	}
	return 0;
}
