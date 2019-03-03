#include <bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int> par;
  vector<int> sizes;
  UnionFind(int n):par(n),sizes(n,1){
    for(int i=0;i<n;i++)par[i] = i;
  }
  int find(int x){
    if(x == par[x])return x;
    return par[x] = find(par[x]);
  }
  void unite(int x,int y){
    x = find(x);y = find(y);
    if(x == y)return;
    if(sizes[x] < sizes[y])swap(x,y);
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x,int y){
    return find(x) == find(y);
  }
  int size(int x){
    return sizes[find(x)];
  }
};

int main(void) {
  int N, M;
  cin >> N >> M;

  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b; a--; b--;
    A[i] = a;
    B[i] = b;
  }

  UnionFind uf(N);
  long long inconv = (long long)N * (N - 1) / 2;
  vector<long long> inconvs;
  for (int i = M - 1; i >= 0; i--) {
    inconvs.push_back(inconv);
    if (!uf.same(A[i], B[i])) {
      inconv = inconv - uf.size(B[i]) * uf.size(A[i]);
    }
    uf.unite(A[i], B[i]);
  }

  reverse(inconvs.begin(), inconvs.end());
  for (auto inconv : inconvs) {
    cout << inconv << endl;
  }

  return 0;
}