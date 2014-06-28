#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<cmath>
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<cctype>
#include<climits>
#include<ctime>
#define INF INT_MAX
#define ll long long
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)

using namespace std;

int main() {
	int n,a,b,ret=0;
	cin >> n >> a >> b;
	for(int i=0;i<n;i++){
		if(i<5)ret += b;
		else ret += a;
	}
	cout << ret << endl;
	return 0;
}