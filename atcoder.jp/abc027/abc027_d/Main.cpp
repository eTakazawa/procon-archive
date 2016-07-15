#include <bits/stdc++.h>
using namespace std;

string s;

long long dfs(int m,int a,int b){
	if(m == 0 && a == 0 && b == 0)return 0;

}

int main(void){
	cin >> s;
	int m,a,b;

	vector<int> diff;
	for(int i=0;i<s.size();i++){
		if(s[i] == '+')a++;
		else if(s[i] == '-')b++;
		else{
			diff.push_back(a-b);
		}
	}
	sort(diff.begin(),diff.end());
	long long ret = 0;
	for(int i=0;i<diff.size()/2;i++){
		ret += -diff[i] + diff[diff.size()-i-1];
	}
	cout << ret << endl;
	return 0;
}