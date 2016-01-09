#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	int k;
	cin >> s >> k;
	set<string> st;
	for(int i=0;i<(int)s.size()-k+1;i++){
		st.insert(s.substr(i,k));
	}
	cout << st.size() << endl;
	return 0;
}