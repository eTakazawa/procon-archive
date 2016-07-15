#include <bits/stdc++.h>
using namespace std;

vector<string> vs;
void dfs(int n,string s,int N){
	if(n == N){
		vs.push_back(s);
		return;
	}
	dfs(n+1,s+"a",N);
	dfs(n+1,s+"b",N);
	dfs(n+1,s+"c",N);
}

int main(void){
	int N;
	cin >> N;

	dfs(0,"",N);
	sort(vs.begin(),vs.end());
	for(int i=0;i<vs.size();i++){
		cout << vs[i] << endl;
	}

	return 0;
}