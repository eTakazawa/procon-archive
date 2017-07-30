#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int mx = -1e9;
  int cnt = 0;
  for (int i=0;i<n;i++) {
    int a;
    cin >> a;
    if (mx < a)
      cnt++;
    mx = max(mx,a);
  }
  cout << cnt << endl;

  return 0;
}