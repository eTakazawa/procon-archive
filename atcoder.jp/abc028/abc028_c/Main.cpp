#include <bits/stdc++.h>
using namespace std;

int main(void){
	vector<int> ar(5);
	for(int i=0;i<5;i++)
		cin >> ar[i];

	vector<int> sum;
	for(int i=0;i<5;i++)
		for(int j=i+1;j<5;j++)
			for(int k=j+1;k<5;k++)
				sum.push_back(ar[i]+ar[j]+ar[k]);
	sort(sum.begin(),sum.end(),greater<int>());
	sum.erase(unique(sum.begin(),sum.end()),sum.end());
	cout << sum[2] << endl;

	return 0;
}