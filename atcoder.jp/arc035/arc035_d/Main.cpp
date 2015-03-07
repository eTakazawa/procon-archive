#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-8;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

template <class T>
struct fenwick_tree {
  vector<T> x;
  fenwick_tree(int n) : x(n, 0) { }
  T sum(int i, int j) {
    if (i == 0) {
      T S = 0;
      for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
      return S;
    } else return sum(0, j) - sum(0, i-1);
  }
  void add(int k, T a) {
    for (; k < x.size(); k |= k+1) x[k] += a;
  }
};

double facl[404000];

double combi(int l1,int r1,int l2,int r2){
	int dx = l2-l1;
	int dy = r2-r1;
	if(dx == 0 || dy == 0 )return 0;
	return facl[dx+dy] - facl[dx] - facl[dy];
}
int main(void) {
	int n;
	cin >> n;
	vector<ll> p(n),q(n);
	vector<double> path(n-1);
	facl[1]=0;
	for(int i=1;i<=400000;i++) facl[i+1]=facl[i]+log(i+1);
	for(int i=0;i<n;i++){
		cin >> p[i] >> q[i];
	}
	fenwick_tree<double> ft(n);
	for(int i=0;i<n-1;i++){
		path[i] = combi(p[i],q[i],p[i+1],q[i+1]);
		ft.add(i,path[i]);
	}

	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++){
		int t;
		cin >> t;
		if(t == 1){
			int k,a,b;
			cin >> k>> a >> b;
			k--;
			if(k!=0){
				double d = combi(p[k-1],q[k-1],a,b);
				ft.add(k-1,d-path[k-1]);
				path[k-1] = d;
			}
			if(k!=n-1){
				double d = combi(a,b,p[k+1],q[k+1]);
				ft.add(k,d-path[k]);
				path[k] = d;
			}
			p[k] = a;
			q[k] = b;
		}else{
			int l1,r1,l2,r2;
			cin >> l1 >> r1 >> l2 >> r2;l1--;r1--;l2--;r2--;
			if(ft.sum(l1,r1-1) > ft.sum(l2,r2-1)){
				cout << "FIRST" << endl;
			}else{
				cout << "SECOND" << endl;
			}
		}
	}
	return 0;
}
