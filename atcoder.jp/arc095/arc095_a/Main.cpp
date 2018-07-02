#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<pair<int,int>> X;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    X.emplace_back(x, i);
  }
  sort(X.begin(), X.end());
  vector<int> rank(N);
  for (int i = 0; i < N; i++) {
    pair<int,int> p = X[i];
    rank[p.second] = i;
  }

  int l = X[N / 2 - 1].first;
  int r = X[N / 2].first;
  cerr << l << " " << r << endl;
  for (int i = 0; i < N; i++) {
    if (rank[i] < N / 2) cout << r << endl;
    else cout << l << endl;
  }


  return 0;
}