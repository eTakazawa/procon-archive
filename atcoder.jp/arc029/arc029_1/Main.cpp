#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<int> t(n);
	for(int i=0;i<n;i++)cin >> t[i];
	sort(t.begin(),t.end());
 
	int T1=0,T2=0;
	for(int i=n-1;i>=0;i--){
		if(T1>T2)T2 += t[i];
		else T1 += t[i];
	}
	cout << max(T1,T2) << endl;
	return 0;
}