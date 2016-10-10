#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,A,B;
	cin >> N >> A >> B;
	string s;
	cin >> s;


	int cnt = 0,cnt2 = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == 'a'){
			if( cnt < A + B ){
				cnt++;
				cout << "Yes" << endl;
			}
			else cout << "No" << endl;
		}

		else if(s[i] == 'b'){
			if( cnt < A + B ){
				if( cnt2 < B ){
					cnt2++;
					cnt++;
					cout << "Yes" << endl;
				}else cout << "No" << endl;
			}else cout << "No" << endl;
		}
		else cout << "No" << endl;

	}


	return 0;
}