#include <algorithm>
#include <iostream>
#include <map>
#include <cstdlib>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <functional>
#include <typeinfo>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int ato(char s){
	return s - '0';
}

int main(void) {
	string s;
	cin >> s;
	int a=0,b=0;
	for(int i=0;i<s.size();i++){
		if((s.size()-i)%2==0)
			a += ato(s[i]);
		else
			b += ato(s[i]);
	}
	cout << a << " " << b << endl;
}