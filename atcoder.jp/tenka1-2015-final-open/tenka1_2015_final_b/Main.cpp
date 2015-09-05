#include <bits/stdc++.h>
using namespace std;

int main(void){
	int V,E,K;
	cin >> V >> E >> K;
	vector<vector<int>> es(V,vector<int>(V,0));
	for(int i=0;i<E;i++){
		int a,b;
		cin >> a >> b;
		es[a][b] = es[b][a] = 1;
	}

	vector<int> res(K);
	for(int i=0;i<(1<<V);i++){
		if(__builtin_popcount(i) != K)continue;
		int id = 0;
		for(int j=0;j<V;j++){
			if( (i>>j) & 1 ){
				res[id] = j;
				id++;
			}
		}
		bool f = true;
		for(int j=0;j<K;j++){
			for(int k=j+1;k<K;k++){
				if(es[res[j]][res[k]])f = false;
			}
		}
		if(f){
			break;
		}
	}
	for(int i=0;i<K;i++)
		cout << res[i] << endl;

	return 0;
}