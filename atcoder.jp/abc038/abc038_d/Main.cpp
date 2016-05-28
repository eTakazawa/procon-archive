#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{// [i,j)
	int n;vector<long long> v;
	SegmentTree(int n_){
		for(n =1;n < n_;n *= 2);
		v = vector<long long>(n * 2 - 1,LLONG_MIN);
	}
	void set(int i,long long x){
		int k = i + n - 1;
		v[k] = max(v[k], x);	// 葉を更新
		while(k > 0){	// kは半分ずつ小さくなる
			k = (k - 1) / 2;	// 親の頂点へ
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);	// 親の子のmax値に更新
		}
	}
	long long _get(int i,int j,int k,int l,int r){
		if(r <= i || j <= l)return LLONG_MIN;	// 交差しない
		if(i <= l && r <= j)return v[k];
		long long vl = _get(i,j,k*2+1,l,(l+r)/2);
		long long vr = _get(i,j,k*2+2,(l+r)/2,r);
		return max(vl,vr);
	}
	long long get(int i,int j){ // [i,j)
		return _get(i,j,0,0,n);
	}
};

int main(void){
	int N;
	cin >> N;
	vector<pair<int,int>> bs;
	for(int i=0;i<N;i++){
		int w,h;
		cin >> w >> h;
		bs.push_back(make_pair(w,-h));
	}
	sort(bs.begin(),bs.end());
	vector<int> ws(N);
	for(int i=0;i<N;i++){
		ws[i] = -bs[i].second;
	}

	SegmentTree st(1e5+1);
	st.set(0,0);
	for(int i=0;i<N;i++){
		st.set( ws[i], st.get(0,ws[i]) + 1 );
	}
	cout << st.get(0,1e5+1) << endl;

	return 0;
}