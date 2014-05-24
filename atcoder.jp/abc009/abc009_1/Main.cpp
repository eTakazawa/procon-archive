#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#define INF 99999999
using namespace std;
int va[100];
int main(){
	int a=0;
	cin >> a;
	if(a%2==0)cout << a/2 << endl;
	else cout << a/2 +1 << endl;
	return 0;
}
