#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;string s;
	cin >> n >> s;
	if(n%2==0){
		cout << -1 << endl;
		exit(0);
	}

	string t;
	for(int i=0;i<=100;i++){
		if(i == 0)t += 'b';
		else if(i%3==1){
			t = "a" + t + "c";
		}else if(i%3==2){
			t = "c" + t + "a";
		}else{
			t = "b" + t + "b";
		}
		if(s == t){
			cout << i << endl;
			exit(0);
		}
	}
	cout << -1 << endl;
	return 0;
}