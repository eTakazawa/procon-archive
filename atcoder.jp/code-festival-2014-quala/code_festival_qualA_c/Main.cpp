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
	int a,b;
	int cnt = 0;
	cin >> a >> b;
	a--;
	int ret = (b/4 - b/100 + b/400)-(a/4 - a/100 + a/400);
	cout << ret << endl;

/*	for(int i=1;i<=1988;i++){
		if(( i % 4 ) == 0 && ( i % 100 ) != 0 || ( i % 400 ) == 0)
			cnt++;
	}
	cout << cnt<< endl;
	*/return 0;
}
