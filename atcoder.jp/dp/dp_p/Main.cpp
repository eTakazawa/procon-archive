#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> es;
constexpr long long MOD = 1000000007;
long long memo[2][100001];

long long dfs(int par, int par_color, int node) {
  long long ret1 = 1, ret2 = 1;
  // cerr << par << " " << node << endl;

  if (memo[par_color][node] != 0) return memo[par_color][node];

  // 白の時のみ黒を許可
  if (par_color == 1) {
    for (int child : es[node]) {
      if (child == par) continue;
      ret1 = (ret1 * dfs(node, 0, child)) % MOD;
    }
  } else {
    ret1 = 0;
  }
  for (int child : es[node]) {
    if (child == par) continue;
    ret2 = (ret2 * dfs(node, 1, child)) % MOD;
  }

  return memo[par_color][node] = (ret1 + ret2) % MOD;
}

int main(void) {
  cin >> N;
  es.resize(N);

  int x, y;
  for (int i = 0; i < N - 1; i++) {
    cin >> x >> y;
    x--;y--;
    es[x].push_back(y);
    es[y].push_back(x);
  }
  cout << dfs(-1, 1, 0) << endl;
  return 0;
}