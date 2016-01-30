#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,set<int>> mp;
	set<int> A;

	int num=1e9,now;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]].insert(i);
		mp[a[i]].insert(i+n);
		A.insert(a[i]);

		if(num > a[i]){
			num = a[i];
			now = i;
		}
	}

	int ret = 1;
	auto at = A.begin();
	now = -1;

	for(;;){
		auto it = mp[num].upper_bound(now);
		if(*it >= n)ret++;
		// cout << now << " " << num << " " << ret << endl;
		now = *it;
		now %= n;
		mp[num].erase(now);
		mp[num].erase(now+n);
		if(mp[num].size() == 0){
			at++;
			if(at == A.end()){
				if(now%n == 0)ret--;
				break;
			}
			// cout << *at << endl;
			num = *at;
		}
	}

	cout << ret << endl;

	return 0;
}