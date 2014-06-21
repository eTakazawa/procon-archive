#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>
#include<cctype>
#include<climits>
#include<ctime>
#define INF INT_MAX
 
using namespace std;
 
 
int d[100][100];
int main() {
	string s, s1;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0)
			s1 += toupper(s[i]);
		else
			s1 += tolower(s[i]);
	}
	cout << s1 << endl;
	return 0;
}