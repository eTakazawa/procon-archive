#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double memo[302][302][302];
int N;

double dfs(int one, int two, int thr) {
  if (memo[one][two][thr] != 0) return memo[one][two][thr];

  if (one == 1 && two == 0 && thr == 0) {
    return N;
  }

  double ret = 0;
  int num_ok = one + two + thr;
  if (thr > 0) ret += (1.0 * thr / num_ok) * dfs(one, two + 1, thr - 1);
  if (two > 0) ret += (1.0 * two / num_ok) * dfs(one + 1, two - 1, thr);
  if (one > 0) ret += (1.0 * one / num_ok) * dfs(one - 1, two, thr);

  // 次のステップに進めるまでに掛かる回数の期待値
  double e = 1.0 / (1.0 * num_ok / N);
  return memo[one][two][thr] = e + ret;
}

int main(void) {
  cin >> N;
  vector<int> a(N);
  vector<int> cnt(3);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    cnt[a[i] - 1]++;
  }

  cout << fixed << setprecision(10) << dfs(cnt[0], cnt[1], cnt[2]) << endl;
  
  return 0;
}