#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int main(void){
	string s;
	cin >> s;
	
	for(int i=0;i<s.size();i++){
		cnt[s[i] - 'a']++;
	}

	int even = 0,odd = 0;
	for(int i=0;i<26;i++){
		if(cnt[i] % 2 == 0){
			even += cnt[i]/2;
		}else{
			even += (cnt[i] - 1)/2;
			odd++;
		}
	}

	if(odd == 0)
		cout << even * 2 << endl;
	else
		cout << 1 + (even/odd) * 2 << endl;

	return 0;
}