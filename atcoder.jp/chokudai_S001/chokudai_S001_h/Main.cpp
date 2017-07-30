#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> l;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(l.begin(),l.end(),a[i]);
    if(it == l.end()) {
      l.push_back(a[i]);
    }else{
      *it = min(*it, a[i]);
    }
  }
  cout << l.size() << endl;

  return 0;
}