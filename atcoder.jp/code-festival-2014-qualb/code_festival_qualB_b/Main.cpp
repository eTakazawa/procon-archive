#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include<utility>
using namespace std;

int main(void){
	int n,k,sum=0;
	cin >> n >>k;
	int ret;
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		sum += a;
		if(sum>=k){
			ret = i;
			break;
		}
	}
	cout << ret << endl;
	return 0;
}
