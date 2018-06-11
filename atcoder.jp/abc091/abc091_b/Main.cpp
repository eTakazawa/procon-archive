#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  map<string, int> mp;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    // if (mp.find(s[i]) == mp.end()) mp[s[i]] = 0;
    // else 
      mp[s[i]]++;
  }
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t[i];
    // if (mp.find(t[i]) == mp.end()) mp[t[i]] = 0;
    // else
      mp[t[i]]--;
  }

  int ret = 0;
  for (auto m : mp) {
    ret = max(ret, m.second);
  }
  cout << ret << endl;

  return 0;
}