#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long H, W;
  cin >> H >> W;

  // 縦に分割
  long long r1 = (W % 3 != 0) * H;
  long long r2 = (H % 3 != 0) * W;

  long long r3, r4;
  r3 = r4 = 1e18;
  for (int h = 1; h < H; h++) {
    long long s1 = W * h;
    long long s2 = (W / 2) * (H - h);
    long long s3 = (W / 2 + W % 2) * (H - h);
    long long max_s = max({s1, s2, s3});
    long long min_s = min({s1, s2, s3});
    r3 = min(r3, max_s - min_s);
    // cerr << min_s << " " << max_s << endl;
  }
  swap(H, W);
  for (int h = 1; h < H; h++) {
    long long s1 = W * h;
    long long s2 = (W / 2) * (H - h);
    long long s3 = (W / 2 + W % 2) * (H - h);
    long long max_s = max({s1, s2, s3});
    long long min_s = min({s1, s2, s3});
    r4 = min(r4, max_s - min_s);
    // cerr << min_s << " " << max_s << endl;
  }
  cout << min({r1, r2, r3, r4}) << endl;

  return 0;
}