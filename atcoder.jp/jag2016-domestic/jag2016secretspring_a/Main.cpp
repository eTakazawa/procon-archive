#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;

	int cnt = 0;
	for(int i=0;i<n;i++){
		string s;cin >> s;
		if(s == "A")cnt++;
		else cnt--;
		if(cnt < 0){
			cout << "NO" << endl;
			exit(0);
		}
	}
	if(cnt == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}