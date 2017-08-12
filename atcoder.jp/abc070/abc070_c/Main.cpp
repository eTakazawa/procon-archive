#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main(void) {
  int N;
  cin >> N;
  vector<long long> t(N);
  long long ret = 1;
  for(int i=0;i<N;i++){
    cin >> t[i];
    ret = lcm(ret,t[i]);
  }
  cout << ret << endl;
  return 0;
}