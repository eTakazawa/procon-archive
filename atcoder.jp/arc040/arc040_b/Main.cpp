#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	int n,r;
	cin >> n >> r;
	string s;
	cin >> s;

	int last = -1;
	for(int i=n-1;i>=0;i--){
		if(s[i] == '.'){
			last = i;
			break;
		}
	}
	if(last == -1){
		cout << 0 << endl;
		return 0;
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '.'){
			cnt++;
			if(i+r-1 >= last){
				break;
			}else{
				for(int j=i;j<=i+r-1&&j<n;j++){
					s[j] = 'o';
				}
			}
		}else if(i+r-1 >= last){
			cnt++;
			break;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}