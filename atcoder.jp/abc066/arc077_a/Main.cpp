#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  
  list<int> b;
  if(n % 2 == 0){
    for(int i=0;i<n;i++){
      if(i%2==0)b.push_back(a[i]);
      else b.push_front(a[i]);
    }
  }else{
    for(int i=0;i<n;i++){
      if(i%2==0)b.push_front(a[i]);
      else b.push_back(a[i]);
    }
  }
  for(auto x : b) {
    cout << x << " ";
  }cout << endl;

  return 0;
}