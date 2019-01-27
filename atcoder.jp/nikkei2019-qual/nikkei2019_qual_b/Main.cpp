#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    set<char> st;
    st.insert(a[i]);
    st.insert(b[i]);
    st.insert(c[i]);
    cnt += (int)st.size() - 1;
  }
  cout << cnt << endl;
  return 0;
}