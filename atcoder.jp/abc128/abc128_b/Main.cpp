#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> r;
  string s;
  int p;
  for (int i = 0; i < N; i++) {
    cin >> s >> p;
    r.emplace_back(s, -p, i);
  }
  sort(r.begin(), r.end());
  for (int i = 0; i < N; i++) {
    cout << get<2>(r[i]) + 1 << endl;
  }
  return 0;
}