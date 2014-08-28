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
#define mod 1000000007
using namespace std;
 
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
 
int main(void) {
	string s1,s2,t1,t2;
	int tmp = 0,t=0,c[26]={};
 
 
	cin >> s1 >> s2;
	t1 = s1;t2 = s2;
	sort(t1.begin(),t1.end());
	sort(t2.begin(),t2.end());
	if(t1!=t2){
		cout << "NO" << endl;
		return 0;
	}
 
	bool f=false;
	for(int i=0;i<s1.size();i++){
		if(s1[i]==s2[i])tmp++;
		else t++;
		if(++c[s1[i]-'a'] > 1)f=true;;
	}
 
 
	if(t>6)cout << "NO" << endl;
	else if(t==2 || (t==4&&f) || t==6)cout << "YES" << endl;
	else{
		if(f)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}