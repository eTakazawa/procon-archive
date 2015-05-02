#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a.begin(),a.end(),greater<int>());
	int sum = 0;
	for(int i=0;i<n;i++){
		if(i%2==0)sum += a[i];
	}
	cout << sum << endl;

	return 0;
}