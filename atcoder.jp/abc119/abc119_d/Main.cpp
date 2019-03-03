#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<long long> s(A + 2), t(B + 2), x(Q);
  s[0] = t[0] = -1e18;
  s[A + 1] = t[B + 1] = 1e18;
  for (int i = 0; i < A; i++) {
    cin >> s[i + 1];
  }
  for (int i = 0; i < B; i++) {
    cin >> t[i + 1];
  }
  for (int i = 0; i < Q; i++) {
    cin >> x[i];
  }

  for (int i = 0; i < Q; i++) {
    long long ret = 1e18;
    auto it1 = lower_bound(s.begin(), s.end(), x[i]);
    auto it2 = lower_bound(t.begin(), t.end(), x[i]);
    cerr << *it1 << endl;
    cerr << *it2 << endl;
    {
      auto it1 = lower_bound(s.begin(), s.end(), x[i]);
      auto it2 = lower_bound(t.begin(), t.end(), x[i]);
      ret = min(ret, abs(max(*it1, *it2) - x[i]));
    }
    {
      auto it1 = lower_bound(s.begin(), s.end(), x[i]);
      auto it2 = lower_bound(t.begin(), t.end(), x[i]);
      it1--;
      it2--;
      ret = min(ret, abs(min(*it1, *it2) - x[i]));
    }
    {
      auto it1 = lower_bound(s.begin(), s.end(), x[i]);
      auto it2 = lower_bound(t.begin(), t.end(), x[i]);
      it2--;
      long long d = min(abs(*it1 - x[i]), abs(*it2 - x[i]));
      ret = min(ret, abs(*it1 - x[i]) + abs(*it2 - x[i]) + d);
    }
    {
      auto it1 = lower_bound(s.begin(), s.end(), x[i]);
      auto it2 = lower_bound(t.begin(), t.end(), x[i]);
      it1--;
      long long d = min(abs(*it1 - x[i]), abs(*it2 - x[i]));
      ret = min(ret, abs(*it1 - x[i]) + abs(*it2 - x[i]) + d);
    }
    cout << ret << endl;
  }

  return 0;
}