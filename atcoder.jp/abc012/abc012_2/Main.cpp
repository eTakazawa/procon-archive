#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<cstdio>
using namespace std;

int main(){
	int n;
	cin >> n;
	printf("%02d:%02d:%02d",n/3600,(n%3600)/60,((n%3600)%60)%60);
	return 0;
}