#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

long long f(long long b) {
  long long ret = 0;
  for (int i = 0; i < N; i++) {
    ret += abs(A[i] - (b + i + 1));
  }
  return -ret;
}

double search(double left, double right)
{
  int maxLoop = 1e3;
  for (int loop = 0; loop < maxLoop; ++loop){
    if (f((left * 2 + right) / 3) > f((left + right * 2) / 3)){
      right = (left + right * 2) / 3;
    } else {
      left = (left * 2 + right) / 3;
    }
  }
  return (right + left) * 0.5;
}

int main(void) {
  cin >> N;
  A = vector<int>(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  // cerr << search(-1e6, 1e9) << endl;
  long long avg = search(-1e6, 1e9);
  long long ret = 1e18;
  for (int d = -100; d <= 100; d++) {
    long long m = 0;
    for (int i = 0; i < N; i++) {
      m += abs(A[i] - (avg + i + d));
    }
    ret = min(ret, m);
  }
  cout << ret << endl;


  return 0;
}