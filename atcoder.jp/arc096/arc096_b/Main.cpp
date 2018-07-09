#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  long long C;
  cin >> N >> C;
  vector<long long> x(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> v[i];
  }

  vector<long long> R_cals(N), L_cals(N);
  vector<long long> R_max_cals(N), L_max_cals(N);
  vector<long long> R_b_cals(N), L_b_cals(N);
  long long cal = 0, nowx = 0;
  for (int i = 0; i < N; i++) {
    cal = cal - abs(nowx - x[i]);
    cal += v[i];
    R_cals[i] = cal;
    R_b_cals[i] = cal - x[i];
    if (i != 0) R_max_cals[i] = max(R_max_cals[i - 1], cal);
    else R_max_cals[i] = cal;
    nowx = x[i];
  }
  // for (int i = 0; i < N; i++) {
  //   cerr << R_cals[i] << " " << R_max_cals[i] << " " << R_b_cals[i] << endl;
  // }

  cal = 0, nowx = C;
  for (int i = 0; i < N; i++) {
    int id = N-1-i;
    cal = cal - abs(nowx - x[id]);
    cal += v[id];
    L_cals[i] = cal;
    L_b_cals[i] = cal - abs(C - x[id]);

    if (i != 0) L_max_cals[i] = max(L_max_cals[i - 1], cal);
    else L_max_cals[i] = cal;
    nowx = x[id];
  }

  // 左にi個行って戻ってくる
  long long ret = 0;
  for (int i = 0; i < N-1; i++) {
    ret = max(ret, L_b_cals[i] + R_max_cals[N-1-i-1]);
    ret = max(ret, R_b_cals[i] + L_max_cals[N-1-i-1]);
  }
  ret = max(R_max_cals[N-1], ret);
  ret = max(L_max_cals[N-1], ret);
  cout << ret << endl;
  return 0;
}