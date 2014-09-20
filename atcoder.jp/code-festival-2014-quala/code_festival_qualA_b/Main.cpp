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

//A
int main(void) {
	string a;
	long long b;
	cin >> a >> b;
	int n;
	n = b%(long long)a.size();
	if(n==0)cout << a[a.size()-1] << endl;
	else cout << a[n-1] << endl;

	return 0;
}
