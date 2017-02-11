#include <bits/stdc++.h>
using namespace std;

int e[9][9];
int main(void){
	int N,M;
	cin >> N >> M;

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;a--;b--;
		// es[a].push_back(b);
		// es[b].push_back(a);
		e[a][b] = e[b][a] = 1;
	}

	vector<int> path(N);
	for(int i=0;i<N;i++)
		path[i] = i;
	
	int cnt = 0;
	do{
		bool ch = true;
		for(int i=0;i<N-1;i++){
			if( e[path[i]][path[i+1]] == 0 )ch = false;
		}
		if(ch)cnt++;
	}while(next_permutation(path.begin()+1,path.end()));
	cout << cnt << endl;
	return 0;
}
