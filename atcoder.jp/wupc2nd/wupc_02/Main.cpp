#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int memo[101];
int dfs(int x) {
  if (memo[x] != -1) return memo[x];
  if (x == N - 1) return 0;
  int ret = 1e9;
  for (int i = 1; i <= 3; i++) {
    if (x + i >= N) break;
    ret = min(ret, dfs(x + i) + (s[x+i] == 'X' ? 1 : 0));
  }
  return memo[x] = ret;
}

int main(void) {
  cin >> N >> s;
  memset(memo, -1, sizeof(memo));
  cout << dfs(0) << endl;


  return 0;
}