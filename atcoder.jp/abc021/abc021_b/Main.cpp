#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	int n,a,b;
	cin >> n >> a >> b;
	set<int> st;
	st.insert(a);
	st.insert(b);
	int k;
	cin >> k;
	for(int i=0;i<k;i++){
		int p;cin >> p;
		if(st.find(p) != st.end()){
			cout << "NO" << endl;
			return 0;
		}
		st.insert(p);

	}
	cout << "YES" << endl;
	return 0;
}
