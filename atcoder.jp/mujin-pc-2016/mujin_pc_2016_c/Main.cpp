#include <bits/stdc++.h>
using namespace std;
int N,M;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

int main(void){
	cin >> N >> M;

	int es[20][20];
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			es[i][j] = 0;
		}
	}
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;x--;y--;
		es[x][y] = 1;
		es[y][x] = 1;
	}

	int cnt = 0;
	for(int i=1;i<(1<<N)-1;i++){
		vector<int> v(N);
		UnionFind uf(30);
		for(int k=0;k<N;k++){
			if((i>>k)&1)v[k] = 1;
		}
		for(int j=0;j<N;j++){
			for(int k=j+1;k<N;k++){
				if( v[j] != v[k] && es[j][k] == 1 ){
					uf.unite( j, k);
				}
			}
		}
		bool ok = true;
		for(int j=0;j<N-1;j++){
			if(!uf.find(j,j+1))ok = false;
		}
		if(ok)cnt++;
	}
	cout << cnt/2 << endl;
	return 0;
}