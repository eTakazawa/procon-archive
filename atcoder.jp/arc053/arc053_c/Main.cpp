#include <bits/stdc++.h>
using namespace std;

vector<pair<long long,pair<long long,long long>>> v1;
vector<pair<long long,pair<long long,long long>>> v2;

int main(void){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		long long a,b;cin >> a >> b;
		if( a - b > 0){
			v1.push_back(make_pair(-b,make_pair(a,a-b)));
		}else{
			v2.push_back(make_pair(a,make_pair(b,a-b)));
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	long long now = 0;
	long long ret = 0;
	for(int i=0;i<v2.size();i++){
		now += v2[i].first;
		ret = max(ret,now);
		now -= v2[i].second.first;
	}
	for(int i=0;i<v1.size();i++){
		now += v1[i].second.first;
		ret = max(ret,now);
		now += v1[i].first;
	}
	cout << ret << endl;

	return 0;
}