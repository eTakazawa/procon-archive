#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  vector<pair<int,int>> diffidx;
  long long suma = 0, sumb = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    suma += A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
    sumb += B[i];
    diffidx.emplace_back(-(A[i] - B[i]), i);
  }

  if (suma < sumb) {
    cout << -1 << endl;
    return 0;
  }

  // 差が最大のやつから借りてくるのがベスト？
  sort(diffidx.begin(), diffidx.end());
  for (int i = 0;i < N;i ++)
    diffidx[i].first = -diffidx[i].first;

  int maxid = 0;
  int ret = 0;
  for (int i = 0; i < N; i++) {
    int nokori = B[i] - A[i];
    // cerr << nokori << endl;
    if (nokori > 0) ret++;
    while (nokori > 0) {
      if (diffidx[maxid].first <= 0) {
        cout << -1 << endl;
        return 0;
      }
      if (nokori < diffidx[maxid].first) {
        diffidx[maxid].first -= nokori;
        nokori = 0;
      } else {
        nokori -= diffidx[maxid].first;
        diffidx[maxid].first = 0;
      }
      if (diffidx[maxid].first == 0) maxid++;
    }
  }
  for (int i = 0; i < N; i++) {
    int id2 = diffidx[i].second;
    if (diffidx[i].first != (A[id2] - B[id2])) {
      // cerr << i << " " << diffidx[i].first << endl;
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}