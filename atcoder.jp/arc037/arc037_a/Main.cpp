#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	int n;
	cin >> n;
	int ret = 0;
	for(int i=0;i<n;i++){
		int m;cin >> m;
		ret += max(0,80-m);
	}
	cout << ret << endl;

	return 0;
}