#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	int n;
	cin >> n;
	vector<string> vs(n);
	for(int i=0;i<n;i++){
		cin >> vs[i];
	}

	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=vs[i].size()-1;j>=0;j--){
			if(vs[i][j] == '.'){
				cnt++;
				if(i == n-1)break;
				for(int k=j;k<vs[i].size();k++){
					vs[i+1][k] = 'o';
				}
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}