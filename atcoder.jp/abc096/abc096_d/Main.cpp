#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
  for(int i=2; i*i <= n; i++) {
    if(n%i == 0)return false;
  }
  return n != 1;
}

int main(void) {
  int N;
  cin >> N;

  vector<int> ps;
  for (int i = 2; i <= 55555; i++) {
    if (is_prime(i) && i % 10 == 7) {
      ps.push_back(i);
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ps[i];
    if (i != N - 1) cout << " ";
  }
  cout << endl;
  // cout << ps.size() << endl;
  // for (int i = 0; i < ps.size(); i++) {
  //   cout << ps[i] << " ";
  // }cout << endl;

  return 0;
}