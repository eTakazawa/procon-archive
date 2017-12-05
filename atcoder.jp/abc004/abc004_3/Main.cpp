#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  N %= 30;
  string s = "123456";
  for (int i = 0; i < N; i++) {
    swap(s[i % 5], s[i % 5 + 1]);
  }
  cout << s << endl;
  return 0;
}