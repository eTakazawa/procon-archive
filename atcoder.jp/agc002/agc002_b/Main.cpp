#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,M;
	cin >> N >> M;
	set<int> st;
	st.insert(1);
	vector<int> cnt(N+1,1);

	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		cnt[x]--;
		cnt[y]++;
		if(st.find(x) != st.end()){
			st.insert(y);
		}
		if(cnt[x] == 0)st.erase(x);
	}

	int ans = 0;
	for(auto it=st.begin();it!=st.end();it++){
		if( cnt[*it] > 0 )ans++;
	}
	cout << ans << endl;

	return 0;
}