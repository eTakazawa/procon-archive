#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  if (b < c) swap(b, c);
  if (a < b) swap(a, b);

  int cnt = 0;
  if ((a - b) % 2 == 0) cnt++;
  if ((a - c) % 2 == 0) cnt++;
  
  if (cnt == 0) {
    cout << (2*a - (b + c)) / 2 << endl;
  } else if(cnt == 1) {
    int ret = 0;
    if ((a - b) % 2 == 0) swap(b, c);
    ret += ((a-1) - b) / 2;
    ret += (a - c) / 2;
    cout << ret + 2 << endl;
  } else {
    cout << (2*(a-1) - (b + c)) / 2 + 1 << endl;
  }

  return 0;
}