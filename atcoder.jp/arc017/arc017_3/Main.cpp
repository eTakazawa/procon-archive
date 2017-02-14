#include <bits/stdc++.h>
using namespace std;

map<int,int> sub_sum(vector<int>& a){
	map<int,int> mp;
	for(int i=0;i<(1<<a.size());i++){
		int sum = 0;
		for(int j=0;j<a.size();j++){
			if((i >> j) & 1){
				sum += a[j];
			}
		}
		mp[sum]++;
	}
	return mp;
}

int main(void){
	int n,x;
	cin >> n >> x;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		int p;cin >> p;
		if(i < n/2)a.push_back(p);
		else b.push_back(p);
	}
	map<int,int> ma = sub_sum(a);
	map<int,int> mb = sub_sum(b);

	long long ret = 0; 
	for(auto it=ma.begin();it!=ma.end();it++){
		ret += mb[x - it->first] * it->second;
	}
	cout << ret << endl;

	return 0;
}