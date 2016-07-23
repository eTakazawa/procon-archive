#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,K;
	cin >> N >> K;
	vector<int> D(K);
	for(int i=0;i<K;i++){
		cin >> D[i];
	}


	for(int i=N;1;i++){
		string s = to_string(i);
		bool ok = true;
		for(int j=0;j<s.size();j++){
			bool tmp = true;
			for(int k=0;k<K;k++){
				if(D[k] == s[j] - '0'){
					tmp = false;
					break;
				}
			}
			if(!tmp){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << i << endl;
			break;
		}
	}

	return 0;
}