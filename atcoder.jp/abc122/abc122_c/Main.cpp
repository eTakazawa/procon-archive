#include <bits/stdc++.h>
using namespace std;

int cnt[100001], isa[100001], isc[100001];
int main(void) {
  int N, Q;
  string s;
  cin >> N >> Q;
  cin >> s;

  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'A' && s[i + 1] == 'C') {
      cnt[i] = 1;
      isa[i] = 1;
      isc[i + 1] = 1;
    }
  }
  for (int i = 0; i < s.size() - 1; i++) {
    cnt[i + 1] += cnt[i];
  }

  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l--;r--;
    int ret = cnt[r] - cnt[l] - isa[r];
    // cerr << cnt[r] << " " << cnt[l] << " " << isa[r] << endl;
    if (isa[l]) ret++;
    cout << ret << endl;
  }

  return 0;
}