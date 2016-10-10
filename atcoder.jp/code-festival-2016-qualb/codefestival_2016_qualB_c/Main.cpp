#include <bits/stdc++.h>
using namespace std;

//fenwick_tree
template <class T>
struct fenwick_tree {
	vector<T> x;
	fenwick_tree(int n) : x(n, 0) { }
	T sum(int i, int j) {//両端を含む
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

int main(void){

	int W,H;
	cin >> W >> H;

	vector<tuple<int,int,int>> p;
	fenwick_tree<int> yoko(W+1),tate(H+1);
	int cntYoko = 0, cntTate = 0;

	for(int i=0;i<W;i++){
		int pp;cin >> pp;
		p.emplace_back( pp, 0, i);
	}
	for(int i=0;i<H;i++){
		int qq;cin >> qq;
		p.emplace_back( qq, 1, i);
	}

	sort(p.begin(),p.end());

	long long ret = 0;
	for(int i=0;i<p.size();i++){
		int cost, pq, id;
		tie(cost, pq, id) = p[i];

		if(!pq){
			cntYoko++;
			ret += (long long)cost * (H + 1 - cntTate);
			// cerr << cost * (H - cntTate) << endl;
		}else{
			cntTate++;
			ret += (long long)cost * (W + 1 - cntYoko);
			// cerr << cost * (W - cntYoko) << endl;
		}
	}
	cout << ret << endl;


	return 0;
}