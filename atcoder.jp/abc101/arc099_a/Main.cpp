#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, k;
  cin >> N >> k;
  vector<int> a(N);
  int minid = -1;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] == 1) minid = i;
  }
  if (N == k) {
    cout << 1 << endl;
    return 0;
  }
  int rightstart = minid;
  int ret = 1e9;
  // if (minid < k && minid != 0) {
  //   rightstart = k - 1;
  // }
  // if (minid != 0) {
  //   ret += (minid - 1) / (k - 1) + 1; 
  // }
  // if (rightstart != N-1) {
  //   rightstart = N - 1 - rightstart;
  //   ret += (rightstart - 1) / (k - 1) + 1;
  // }
  // cout << ret << endl;

  // int ret = 0;
  for (int i = minid-k+1; i <= minid+k-1; i++) {
    if (i < 0 || i+k-1 > N-1) continue;
    int cnt = 1;
    int leftstart = i;
    int rightstart = i + k -1;
    if (leftstart != 0) {
      cnt += (leftstart - 1) / (k - 1) + 1; 
    }
    if (rightstart != N-1) {
      rightstart = N - 1 - rightstart;
      cnt += (rightstart - 1) / (k - 1) + 1;
    }
    ret = min(ret, cnt);
  }
  cout << ret << endl;
  return 0;
}