#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <functional>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int main(void) {
	int a,b;
	cin >> a >> b;
	int ret = abs(a-b);
	
	ret = min(ret,9 - (a>b?a:b) + (a<b?a:b) - 0 + 1);
	cout <<ret << endl;
}