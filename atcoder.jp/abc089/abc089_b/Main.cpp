#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  bool isFour = false;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (s == "Y") isFour = true;
  }
  if (isFour) cout << "Four" << endl;
  else cout << "Three" << endl;
  return 0;
}