#include <bits/stdc++.h>
using namespace std;

int det(vector<vector<int>> A){
	const int n = A.size();
	int ret = 1;
	for(int i=0;i<n;i++){
		int j;
		if(A[i][i] == 0){
			for(j=i+1;j<n;j++)
				if(A[j][i])break;
			if(j == n)return 0; // 全行,0
			swap(A[j],A[i]);
		}
		for(j=i+1;j<n;j++)if(A[j][i]){
			for(int z=i;z<n;z++)A[j][z] ^= A[i][z];
		}
	}
	return ret;
}

int main(void){
	int n;
	cin >> n;
	vector<vector<int>> A(n);
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			A[i].push_back(s[j] - '0');
		}
	}
	cout << (det(A) % 2 == 0 ? "Even" : "Odd") << endl;

	return 0;
}