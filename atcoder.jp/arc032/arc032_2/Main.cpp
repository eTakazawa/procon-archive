//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <utility>
#define INF INT_MAX / 2
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define MAX_N 100001

int par[MAX_N];	//親
int rank_union[MAX_N];	//木の深さ

//n要素で初期化
void init_union_find(int n){
	for(int i=0;i<n;i++){
		par[i] = i;
		rank_union[i] = 0;
	}
}
//木の根を求める
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}
//xとyの蔵する集合を併合
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y)return;

	if(rank_union[x] < rank_union[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank_union[x] == rank_union[y])rank_union[x]++;
	}
}
//xとyが同じ集合に属するか否か
bool same(int x,int y){
	return find(x)==find(y);
}

int main(void) {
	int n,m;
	cin >> n >> m;
	init_union_find(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		unite(a,b);
	}

	int cnt = 0;
	for(int i=1;i<n;i++){
		if(!same(0,i)){
			unite(0,i);
			cnt++;
		}
	}
	cout << cnt << endl;
}

// command shift d duplicate
// command ctrl 上下
// command D
// command caps G → '' ""
// vector<vector<int>> a(N,vector<int>(M,-1));