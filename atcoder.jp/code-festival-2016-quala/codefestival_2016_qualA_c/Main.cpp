#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	int K;
	cin >> s >> K;
	int n = s.size()-1;

	for(int i=0;i<s.size();i++){
		// a に戻すまでの必要回数
		if(s[i] == 'a')continue;
		int need = 'z' - s[i] + 1;
		if( need <= K ){
			K -= need;
			s[i] = 'a';
		}
	}
	if( K >= 0 ){
		K %= 26;
		for(int i=0;i<K;i++){
			if(s[n] == 'z')s[n] = 'a';
			else s[n] = s[n] + 1;
		}
	}
	cout << s << endl;

	return 0;
}
