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
#include <stack>
#include <queue>
#include <functional>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int main(void) {
	int a;
	cin >> a;
	for(int i=1;i<=100;i++){
		if(i*i*i==a){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}