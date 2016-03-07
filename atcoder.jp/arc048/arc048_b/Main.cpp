#include <bits/stdc++.h>
using namespace std;

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
	int n;
	cin >> n;
	fenwick_tree<int> ft(100010);
	vector<vector<int>> hands(100010,vector<int>(4));
	vector<int> rs(n),hs(n);
	for(int i=0;i<n;i++){
		int r,h;cin >> r >> h;h--;
		rs[i] = r;
		hs[i] = h;
		ft.add(r,1);
		hands[r][h]++;
	}

	for(int i=0;i<n;i++){
		int lose = ft.sum(rs[i]+1, 100009) + hands[rs[i]][(hs[i]+2)%3];
		int draw = hands[rs[i]][hs[i]] - 1;
		cout << n-1-lose-draw << " " << lose << " " << draw << endl;
	}



	return 0;
}