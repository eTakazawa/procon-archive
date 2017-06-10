#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n;
  cin >> n;
  vector<int> a(n);
  int mx=-1,mn=1e9;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mx = max(mx,a[i]);
    mn = min(mn,a[i]);
  }
  cout << mx - mn << endl;

  return 0;
}