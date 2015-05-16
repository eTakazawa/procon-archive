#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int func(string a,string b,int i,int k,int j){
	if(i == 0){
		a[k] = '0' + j;
		return stoi(a) - stoi(b);
	}else{
		b[k] = '0' + j;
		return stoi(a) - stoi(b);
	}
}

int main(void){
	string a,b;
	cin >> a >> b;
	int ret = -10000;
	for(int i=0;i<2;i++){
		for(int k=0;k<3;k++){
			for(int j=0;j<10;j++){
				if(k == 0 && j == 0)continue;
				ret = max(ret,func(a,b,i,k,j));
			}
		}
	}
	cout << ret << endl;
	return 0;
}