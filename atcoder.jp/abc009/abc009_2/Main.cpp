#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include <functional>
#define INF 99999999
using namespace std;
int main(){
	int n;
	vector<int>v;
	cin >> n;
	for(int i=0;i<n;i++){
		int b;cin >>b;
		v.push_back(b);
	}
	sort(v.begin(),v.end(),greater<int>());

	int rank=0,ret;
	for(int i=0;i<n-1;i++){
		if(v[i]!=v[i+1])rank++;
		if(rank==1)ret = v[i+1];
	}
	if(rank==0)cout << v[0] << endl;
	else cout << ret << endl;
	return 0;
}
