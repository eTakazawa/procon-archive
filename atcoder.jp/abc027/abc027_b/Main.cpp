#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n != 0){
		cout << -1 << endl;
		return 0;
	}

	int avg = sum / n;
	int diff = 0,cnt = 0;
	for(int i=0;i<n;i++){
		diff += a[i] - avg;
		if(diff != 0){
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}