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
	vector<string> vs;
	for(int i=1;i<=1000;i++){
		stringstream ss;
		ss << i;
		string s = ss.str();
		vs.push_back(s);
	}
	sort(vs.begin(),vs.end());
	for(int i=0;i<1000;i++){
		cout << vs[i] << endl;
	}
	return 0;
}
