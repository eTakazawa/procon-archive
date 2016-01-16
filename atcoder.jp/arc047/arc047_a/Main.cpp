#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n,l;
	string s;
	cin >> n >> l;
	cin >> s;
	int tab = 1,wg = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '+')tab++;
		else tab--;
		if(tab > l){
			wg++;
			tab = 1;
		}
	}
	cout << wg << endl;
	return 0;
}