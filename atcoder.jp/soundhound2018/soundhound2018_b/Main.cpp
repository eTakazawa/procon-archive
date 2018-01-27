#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,L,R;
  cin >> n >> L >> R;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a < L) cout << L << " ";
    else if(a > R) cout << R << " ";
    else cout << a << " ";
  }
  cout << endl;
  return 0;
}