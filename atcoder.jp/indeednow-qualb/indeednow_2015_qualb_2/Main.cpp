//weekly CD,SRM div2 hard
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	string s,t;
	cin >> s >> t;
	if(s.size() != t.size()){
		cout << -1 << endl;
		return 0;
	}

	for(int i=0;i<s.size();i++){
		if(s == t){
			cout << i << endl;
			return 0;
		}
		s = s[s.size()-1] + s;
		s.erase(s.size()-1);
		//cout << s << endl;
	}
	cout << -1 << endl;
	return 0;
}

