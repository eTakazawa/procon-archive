#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  priority_queue<tuple<int,int,int>> pq;
  long long ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      if (i > j) {
        pq.emplace(A[i][j], i, j);
        ret += A[i][j];
      }
    }
  }
  vector<vector<int>> orgA = A;
  vector<vector<int>> count(N, vector<int>(N));
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
        if (A[i][j] == A[i][k] + A[k][j]) {
          if (i != k && j != k) {
            if (A[i][j] == A[i][k] + A[k][j])
              count[i][j]++;
          }
        }
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] != orgA[i][j]) ok = false;
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  while (!pq.empty()) {
    vector<long long> dist(N);
    fill(dist.begin(), dist.end(), 1e18);
    tuple<int,int,int> t = pq.top(); pq.pop();
    int val = get<0>(t);
    int v1 = get<1>(t), v2 = get<2>(t);
    if (count[v1][v2]) {
      ret -= val;
    }
  }
  cout << ret << endl;

  return 0;
}