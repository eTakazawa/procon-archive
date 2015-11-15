#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(void){
	int n;cin >> n;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
 
	long long ret = 0;
	int i = 0;
	while(a.size()-i > 1){
		if(a[i]*2+a[i+1] < a[a.size()-1]*2+a[a.size()-2]){
			long long r = a[i]+a[i+1]+2;
			ret += a[i]*2+a[i+1]+1;
			i += 2;
			a[i] += r;
		}else{
			long long r = a[a.size()-1]+a[a.size()-2]+2;
			ret += a[a.size()-1]*2+a[a.size()-2]+1;
			a.pop_back();a.pop_back();
			a[a.size()-1] += r;
		}
	}
	cout << ret << endl;
 
	return 0;
}
