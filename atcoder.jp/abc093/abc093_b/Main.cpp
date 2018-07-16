#include <bits/stdc++.h>
using namespace std;

int main(void) {
  
  int a, b, k;
  cin >> a >> b >> k;
  for (int i = a; i < min(b+1, a + k); i++) {
    cout << i << endl;
  }
  for (int i = max(b-k+1, a+k); i <= b; i++) {
    cout << i << endl;
  }

  return 0;
}