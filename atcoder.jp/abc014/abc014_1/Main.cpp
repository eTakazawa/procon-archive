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

int main(void) {
	int a,b;
	cin >> a >> b;
	if(a<=b){
		cout << b-a << endl;
		return 0;
	}
	for(int i=2;i<101;i++){
		if(a <= b*i){
			cout << b*i -a << endl;
			break;
		}
	}
	
	return 0;
}
