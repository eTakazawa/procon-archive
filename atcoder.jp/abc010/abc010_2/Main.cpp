#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<cmath>
using namespace std;

int main(){
	int n;
	int a[10];
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];

	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i] == 5)ans+=2;
		else if(a[i] == 6)ans+=3;
		else if(a[i]%2 == 0)ans++;
	}

	cout << ans << endl;
	return 0;
}
