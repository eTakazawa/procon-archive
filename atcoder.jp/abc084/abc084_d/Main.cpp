#include <bits/stdc++.h>
using namespace std;

template <class T>
struct fenwick_tree {
  vector<T> x;
  fenwick_tree(int n) : x(n, 0) { }
  T sum(int i, int j) {//両端を含む
    if (i == 0) {
      T S = 0;
      for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
      return S;
    } else return sum(0, j) - sum(0, i-1);
  }
  void add(int k, T a) {
    for (; k < x.size(); k |= k+1) x[k] += a;
  }
};

vector<int> sieve_of_eratosthenes(int n) {
  vector<int> primes(n);
  for (int i = 2; i < n; ++i)
    primes[i] = i;
  for (int i = 2; i*i < n; ++i)
    if (primes[i])
      for (int j = i*i; j < n; j+=i)
        primes[j] = 0;
  return primes;
}

int main(void) {
  int Q;
  cin >> Q;
  int n = 1e5 + 1;
  vector<int> primes = sieve_of_eratosthenes(n);
  fenwick_tree<int> ft(n);
  for (int i = 0; i < n; i++) {
    if (primes[i] && primes[(i + 1) / 2]) {
      ft.add(i, 1);
    }
  }
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << ft.sum(l, r) << endl;
  }


  
  return 0;
}