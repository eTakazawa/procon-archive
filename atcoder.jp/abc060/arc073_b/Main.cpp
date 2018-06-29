#include <bits/stdc++.h>
using namespace std;

int N, W;
int w0;
vector<vector<long long>> wv;
long long maxv;
void dfs(int n, long long w, long long v) {
  if (n == 4) {
    maxv = max(v, maxv);
    return;
  }
  dfs(n + 1, w, v);
  for (int i = 0; i < wv[n].size(); i++) {
    long long nw = w + (long long)(w0 + n) * (i + 1);
    if (nw <= W) dfs(n + 1, nw, v + wv[n][i]);
  }
}

int main(void) {
  cin >> N >> W;
  vector<int> w(N), v(N);
  wv = vector<vector<long long>>(4);
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }
  w0 = w[0];
  for (int i = 0; i < N; i++) {
    wv[w[i] - w0].push_back(v[i]);
  }
  for (int i = 0; i < 4; i++) {
    sort(wv[i].begin(), wv[i].end(), greater<int>());
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < wv[i].size(); j++) {
      wv[i][j] += wv[i][j - 1];
    }
  }
  dfs(0, 0, 0);
  cout << maxv << endl;

  return 0;
}