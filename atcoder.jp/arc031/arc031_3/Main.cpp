#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

//fenwick_tree
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

int main(void) {
	int N;
	cin >> N;
	vector<int> idB(N);
	for(int i=0;i<N;i++){
		int b;cin >> b;b--;
		idB[b] = i;
	}

	fenwick_tree<int> ft(N);
	for(int i=0;i<N;i++)ft.add(i,1);

	ll ret = 0;
	for(int i=0;i<N;i++){
		int ix = idB[i];
		ret += min(ft.sum(0,ix),ft.sum(ix,N-1)) - 1;
		ft.add(ix,-1);
	}
	cout << ret << endl;
	return 0;
}

