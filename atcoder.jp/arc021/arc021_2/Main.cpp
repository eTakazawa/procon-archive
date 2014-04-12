#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

vector<int> a,b;
int main(){
	int l;
	cin >> l;
	for(int i=0;i<l;i++){
		int B;cin >> B;
		b.push_back(B);
	}
	a.push_back(0);
	for(int i=0;i<l-1;i++){
		a.push_back(a[i]^b[i]);
	}
	if((a[l-1]^a[0])!=b[l-1])cout << -1 << endl;
	else{
		for(int i=0;i<l;i++){
			cout << a[i] << endl;
		}
	}
}
