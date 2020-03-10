#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define INF 1e18
int N;
vector<long long> a;
long long memo[2][3001][3001];
long long dfs(int t, int l, int r) {
  // cerr << t << " " << l << " " << r << endl;
  if (memo[t % 2][l][r] != INF) return memo[t % 2][l][r];
  if ((N % 2 == 0 && l + r == N - 1) || (N % 2 == 1 && l + r == N)) {
    return 0;
  }
  long long ret;
  if (t % 2 == 0) {
    ret = -INF;
    ret = max(ret, dfs(t + 1, l + 1, r) + a[l]);
    ret = max(ret, dfs(t + 1, l, r + 1) + a[N - r - 1]);
  }
  else {
    ret = INF;
    ret = min(ret, dfs(t + 1, l + 1, r));
    ret = min(ret, dfs(t + 1, l, r + 1));
  }
  return memo[t % 2][l][r] = ret;
}

int main(void) {
  cin >> N;
  a = vector<long long>(N);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3001; j++) {
      for (int k = 0; k < 3001; k++) {
        memo[i][j][k] = INF;
      }
    }
  }

  long long X = dfs(0, 0, 0);
  // cerr << X << endl;
  long long Y = sum - X;
  cout << X - Y << endl;

  return 0;
}