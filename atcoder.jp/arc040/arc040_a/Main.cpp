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

	int a,b;
	a= b=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<vs[i].size();j++){
			if(vs[i][j] == 'R')a++;
			if(vs[i][j] == 'B')b++;
		}
	}
	if(a > b){
		cout << "TAKAHASHI" << endl;
	}else if(a <b ){
		cout << "AOKI" << endl;
	}else{
		cout << "DRAW" << endl;
	}
	return 0;
}