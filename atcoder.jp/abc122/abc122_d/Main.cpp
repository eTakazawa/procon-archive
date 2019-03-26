#include <bits/stdc++.h>
using namespace std;

map<string, long long> dp[101];
string atgc = "ATGC";
const int MOD = 1000000007;
int N;

bool ok(const string& s) {
  // AGC?, GAC?, ACG?, A?GC, AG?C
  string t = s.substr(0, 3);
  if (t == "AGC" || t == "GAC" || t == "ACG")
    return false;
  if ((s[0] == 'A' && s[2] == 'G' && s[3] == 'C') ||
      (s[0] == 'A' && s[1] == 'G' && s[3] == 'C'))
    return false;
  return true;
}

long long dfs(int i, const string& p, const string& pp, const string& ppp) {
  if (i == N) return 1;
  string prev = p + pp + ppp;
  
  if (dp[i][prev] != 0) return dp[i][prev];
  long long ret = 0;
  for (auto b : atgc) {
    string s = b + prev;
    if (ok(s))
      ret += dfs(i + 1, string(1, b), p, pp) % MOD;
  }
  return dp[i][prev] = ret % MOD;
}

int main(void) {
  cin >> N;
  long long ret = 0;
  cout << dfs(0, "$", "$", "$") << endl;

  return 0;
}