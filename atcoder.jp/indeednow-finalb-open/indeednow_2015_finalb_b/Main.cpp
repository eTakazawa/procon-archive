#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
const int INF = 1e9;

int main(void) {
	int N;
	cin >> N;
	vector<int> s(N),t(N);
	vector<int> qs(N),qt(N);
	for(int i=0;i<N;i++){
		int ss,tt;
		cin >> ss >> tt;
		s[i] = qs[i] = ss;
		t[i] = qt[i] = tt;
	}
	s.push_back(0);t.push_back(0);
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	
	for(int i=0;i<N;i++){
		cout << 
		(lower_bound(s.begin(),s.end(),qt[i]) - s.begin()) -
		(lower_bound(s.begin(),s.end(),qs[i]) - s.begin()) - 1
		<< endl;
	}	


	return 0;
}