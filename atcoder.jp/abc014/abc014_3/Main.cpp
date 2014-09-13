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

//C
int table[1000002];
int main(void){
	int n,a,b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		table[a]++;
		table[b+1]--;
	}

	for(int i=0;i<=1000000;i++)
		if(0 < i)table[i] += table[i-1];

	int cnt=0;
	for(int i=0;i<=1000000;i++) {
		cnt = max(cnt,table[i]);
	}

	cout << cnt << endl;
	return 0;
}
