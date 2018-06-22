#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, a, b;
  cin >> n >> a >> b;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    int d = 0;
    for (int j = 0; j < s.size(); j++) {
      d += s[j] - '0';
    }
    if (a <= d && d <= b) sum += i;
  }
  cout << sum << endl;
  return 0;
}