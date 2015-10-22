#include <bits/stdc++.h>
using namespace std;

int main(void){

	string s;
	vector<char>res;
	while(cin >> s){
		if(s == "Left")
			res.push_back('<');
		else if(s == "Right")
			res.push_back('>');
		else
			res.push_back('A');
	}
	for(int i=0;i<res.size();i++){
		cout << res[i];
		if(i == res.size()-1){
			cout << endl;
		}else
			cout << ' ';
	}

	return 0;
}