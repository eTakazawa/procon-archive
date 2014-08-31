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
#include <queue>
#include <functional>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

//B'
int main(){
	int n,k;
	cin >> n >> k;
	vector<int>x(n);
	priority_queue<pair<int,int> >y;
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	for (int i = 0; i < k; ++i){
		pair<int,int>p(x[i],i);
		y.push(p);
	}

	cout << y.top().second + 1 << endl;

	for(int i=k;i<n;i++){
		pair<int,int>p(x[i],i);
		y.push(p);
		y.pop();
		cout << y.top().second + 1 << endl;
	}

	return 0;
}
