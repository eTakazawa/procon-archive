#include <bits/stdc++.h>
using namespace std;

int main(void){
	int r,c,k,n;
	cin >> r >> c >> k >> n;
	vector<long long> a(r+1),b(c+1);
	set<pair<int,int>> st;
	for(int i=0;i<n;i++){
		int aa,bb;
		cin >> aa >> bb;
		a[aa]++;
		b[bb]++;
		st.insert(make_pair(aa,bb));
	}

	vector<long long> cnta(100001),cntb(100001);
	for(int i=1;i<r+1;i++){
		cnta[a[i]]++;
	}
	for(int i=1;i<c+1;i++){
		cntb[b[i]]++;
	}

	long long sum = 0;
	for(int i=1;i<r+1;i++){
		if(a[i] > k)continue;
		sum += cntb[k-a[i]];
	}

	for(auto it=st.begin();it!=st.end();it++){
		if(a[it->first]+b[it->second] == k)sum--;
		if(a[it->first]+b[it->second] == k+1)sum++;
	}
	cout << sum << endl;

	return 0;
}