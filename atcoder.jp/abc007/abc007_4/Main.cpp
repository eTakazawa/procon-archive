//http://abc007.contest.atcoder.jp/submissions/162197
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

long long dp[20][2];

long long solve(long long a) {
	vector<int> t;
	for (int i = 0; i < 20; ++i) {
		t.push_back((int) (a % 10));
		a /= 10;
	}
	memset(dp, 0, sizeof(dp));
	dp[20][0] = 1;
	for (int i = 20; i > 0; i--) {
		for (int j = 0; j < t[i - 1]; ++j) {
			if (j == 4 || j == 9)
				continue;
			dp[i - 1][1] += dp[i][0] + dp[i][1];
		}
		for (int j = t[i - 1]; j < t[i - 1] + 1; ++j) {
			if (j == 4 || j == 9)
				continue;
			dp[i - 1][1] += dp[i][1];
			dp[i - 1][0] += dp[i][0];
		}
		for (int j = t[i - 1] + 1; j < 10; ++j) {
			if (j == 4 || j == 9)
				continue;
			dp[i - 1][1] += dp[i][1];
		}
	}
	return dp[0][0] + dp[0][1];
}

int main(void) {
	long long A,B;
	cin >> A >> B;
	cout << B - A + 1 -(solve(B) - solve(A-1)) << endl;
	
	return 0;
}
