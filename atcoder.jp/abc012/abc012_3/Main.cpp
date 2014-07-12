#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>

using namespace std;

int main(){
	int n,sum=2025;
	cin >> n;
	n = sum -n;

	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(n == i*j)
				cout << i << " x " << j << endl;
		}
	}
	return 0;
}