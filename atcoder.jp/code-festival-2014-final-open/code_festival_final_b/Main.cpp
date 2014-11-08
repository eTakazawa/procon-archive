#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<utility>

using namespace std;


int main(void){
	string s;
	cin >> s;
	int ret = 0;
	for(int i=0;i<s.size();i++){
		if(i%2==0)ret += s[i] - '0';
		else ret -= s[i] - '0';
	}
	cout << ret;
	return 0;
}
