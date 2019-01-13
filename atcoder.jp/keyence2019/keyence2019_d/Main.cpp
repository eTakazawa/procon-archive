#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main(void) {
  int N, M;
  cin >> N >> M;
  
  vector<int> A(N), B(M);
  set<int> sa, sb;
  int a_min = 1e9, b_min = 1e9;
  // 最小値及び集合で管理
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    a_min = min(a_min, A[i]);
    sa.insert(A[i]);
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
    b_min = min(b_min, B[i]);
    sb.insert(B[i]);
  }
  int ab_min = min(a_min, b_min);

  const int nm = N * M;
  long long ret = 1;
  long long r = 0, c = 0;
  for (int i = nm; i >= 1; i--) {
    bool isa = (sa.find(i) != sa.end());
    bool isb = (sb.find(i) != sb.end());

    // cerr << i << " : " << ret << endl;
    // 両方になし
    if ((!isa) && (!isb)) {
      // まだそれより小さい行列が出てくる
      if (i > ab_min) {
        if ((r * c - (nm - i)) <= 0) {
          cout << 0 << endl;
          return 0;
        }
        ret *= (r * c - (nm - i));
        ret %= MOD;
      }
      // 終わり
      else {
        if ((r * c - (nm - i)) <= 0) {
          cout << 0 << endl;
          return 0;
        }
        ret *= r * c - (nm - i);
        ret %= MOD;
      }
    }
    // 両方にあり
    else if (isa && isb) {
      // 変化なし ret *= 1;
      r++;
      c++;
    }
    // Aのみにあり
    else if (isa) {
      // c通りある
      ret *= c;
      ret %= MOD;
      r++;
    }
    // Bのみにあり
    else if (isb) {
      // r通りある
      ret *= r;
      ret %= MOD;
      c++;
    }
  }
  if (ret < 0) cout << 0 << endl;
  else cout << ret << endl;
  return 0;
}