#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
const int INF = 1e9;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
bool used[101][101];

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
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

struct edge{
    int u,v;
    int cost;
    bool operator<(const edge& e)const{
        return cost > e.cost;
    }
};

class Kruskal{
public:
    UnionFind uf;
    vector<edge> es;
    int V;
    Kruskal(int V,vector<edge> es):uf(V),es(es){}
    int exec(){
        sort(es.begin(),es.end());
        ll res = 0;
        for(int i=0;i<es.size();i++){
            edge e = es[i];
            if(!uf.same(e.u,e.v)){
                uf.unite(e.u,e.v);
                res += e.cost;
            }
        }
        return res;
    }
};

int transgraph(int x,int y,int w){
	return (y*w)+x;
}

int main(void) {
	int h,w;
	int sx,sy,gx,gy;
	cin >> h >> w;
	cin >> sx >> sy >> gx >> gy;
	vector<vector<int>> p(h,vector<int>(w));
	ll sum = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> p[i][j];
			sum += p[i][j];
		}
	}
	vector<edge> es(w*h+1);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<4;k++){
				int nx = j + dx[k],ny = i + dy[k];
				if(nx < 0 || ny < 0 || nx >= w || ny >= h)continue;
				int v = transgraph(j,i,w),nv = transgraph(nx,ny,w);
				int c = p[i][j]*p[ny][nx];
				es.push_back(edge{v,nv,c});
			}
		}
	}
	Kruskal kruskal(w*h+1,es);
	cout << kruskal.exec()+sum << endl;


	return 0;
}