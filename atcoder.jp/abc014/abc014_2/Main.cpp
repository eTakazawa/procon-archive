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

int main(void){
	long long n,X;
	int a[1000];
	cin >> n >> X;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int ret = 0;
	for(int i=0;i<n;i++){
		if(((X>>i)&1))ret += a[i];
	}

	cout << ret << endl;
	return 0;
}
