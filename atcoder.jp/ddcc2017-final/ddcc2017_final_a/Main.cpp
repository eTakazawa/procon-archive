#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int K;
  cin >> K;

  int dx[] = {0,1,0,1};
  int dy[] = {1,0,0,1};
  int cnt1 = 0, cnt2 = 0;
  for (int i=0;i<200;i+=K) {
    for (int j=0;j<200;j+=K) {
      bool ok = true;
      for (int k=0;k<4;k++) {
        double x = j + dx[k] * K, y = i + dy[k] * K;
        double dist = (x - 100)*(x - 100) + (y - 100)*(y - 100);
        if (dist > 100.0*100.0) ok = false;
      }
      if (ok) cnt1++;
    }
  }
  for (int i=0;i<300;i+=K) {
    for (int j=0;j<300;j+=K) {
      bool ok = true;
      for (int k=0;k<4;k++) {
        double x = j + dx[k] * K, y = i + dy[k] * K;
        double dist = (x - 150)*(x - 150) + (y - 150)*(y - 150);
        if (dist > 150.0*150.0) ok = false;
      }
      if (ok) cnt2++;
    }
  }
  cout << cnt1 << " " << cnt2 << endl;
  return 0;
}