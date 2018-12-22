#include <bits/stdc++.h>
using namespace std;

map<long long,int>prime_factor(long long n) {
  map<long long,int>res;
  for(long long i=2; i*i<=n; i++) {
    while(n%i==0) {
      ++res[i];
      n /= i;
    }
  }
  if(n!=1)res[n]=1;
  return res;
}

int main(void) {
  long long N, P;
  cin >> N >> P;
  map<long long,int> primes = prime_factor(P);
  long long ret = 1;
  for (auto it : primes) {
    // cerr << it.first << " " << it.second << endl;
    if (it.second >= N) {
      for (int i = 0; i < it.second / N; i++) {
        ret *= it.first;
      }
    }
  }
  cout << ret << endl;

  return 0;
}