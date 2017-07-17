#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  vector<long long> sum(n+1);
  for(int i=0;i<n;i++){
    sum[i+1] = sum[i] + a[i];
  }

  long long ret = 1e18;
  for(int i=1;i<n;i++){
    ret = min(ret, abs(sum[i] - (sum[n]-sum[i])));
    cerr << sum[n]-sum[i] << endl;
  }
  cout << ret << endl;

  return 0;
}