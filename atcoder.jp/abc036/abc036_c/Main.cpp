#include <bits/stdc++.h>
using namespace std;


int main(void){
	int N;
	cin >> N;
	vector<int> a(N),a_;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	a_ = a;
	sort(a.begin(),a.end());

	map<int,int> mp;
	int r = 0,num = a[0];
	for(int i=0;i<a.size();i++){
		if(a[i] != num){
			num = a[i];
			r++;
		}
		mp[a[i]] = r;
	}

	for(int i=0;i<a_.size();i++){
		cout << mp[a_[i]] << endl;
	}

	return 0;
}