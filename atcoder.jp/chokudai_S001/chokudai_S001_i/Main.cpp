#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = 0,sum = 0,cnt = 0;
  for (int r=0;r<n;r++) {
    sum += a[r];
    if(sum == n)cnt++;
    for(;l<r && sum > n;l++){
      sum -= a[l];
      if(sum == n)cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}