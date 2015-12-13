#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int cnt = 0;
	for(int i=1;i<=555555;i++){
		string s = to_string(i);
		bool f = true;
		for(int j=0;j<s.size()-1;j++){
			if(s[j] != s[j+1])
				f = false;
		}
		if(f)cnt++;
		if(cnt == n){
			cout << i << endl;
			exit(0);
		}

	}

	return 0;
}