#include <bits/stdc++.h>
using namespace std;

vector<long long> hs, ps;
long long solve(long long N, long long X) {
  long long mid = hs[N] / 2;
  cerr << N << " " << mid << " " << X << endl;
  // 全部食べ切る
  if (X == hs[N] - 1) return ps[N];
  // 一番下はB
  if (X == 0) return 0;
  // それ以外
  // ちょうど真ん中なのでN-1バーガー分とmidの位置の分
  if (X == mid) return ps[N - 1] + 1;
  else if (X <= mid) {
    // 真ん中より小さい時
    // 一番下はBなので，Xを一つ下にずらして，N-1バーガー中で解く
    return solve(N - 1, X - 1);
  } else {
    // + 真ん中より下分のバーガーに含まれるP
    return solve(N - 1, X - mid - 1) + ps[N - 1] + 1;
  }
}

// パティの数
// 1
// 3  (= 1*2 + 1)
// 7  (= 3*2 + 1)
// 15 (= 7*2 + 1)

// 高さ
// 1
// 5 (1*2 + 3)
// 13 (5*2 + 3)

int main(void) {
  long long N, X;
  cin >> N >> X;
  long long h = 1, p = 1;
  hs.push_back(h);ps.push_back(p);
  for (int i = 0; i < N; i++) {
    h = h * 2 + 3;p = p * 2 + 1;
    hs.push_back(h);ps.push_back(p);
  }
  cout << solve(N, X - 1) << endl;
  return 0;
}