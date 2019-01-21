#include <bits/stdc++.h>
using namespace std;

int main(void) {
  set<int> st;
  int s;
  cin >> s;
  st.insert(s);
  for (int i = 0;; i++) {
    if (s % 2 == 0) {
      s = s / 2;
    } else {
      s = 3 * s + 1;
    }
    if (st.find(s) != st.end()) {
      cout << i + 2 << endl;
      break;
    }
    st.insert(s);
  }

  return 0;
}