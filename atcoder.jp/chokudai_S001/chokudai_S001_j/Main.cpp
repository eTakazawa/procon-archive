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

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  fenwick_tree<int> ft(1000000+1);

  long long ret = 0;
  for (int i = 0; i < n; i++) {
    ret += ft.sum(a[i],1000000);
    ft.add(a[i], 1);
  }
  cout << ret << endl; 
  return 0;
}