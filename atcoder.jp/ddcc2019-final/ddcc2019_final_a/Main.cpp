#include <bits/stdc++.h>
using namespace std;

int max_cnt;
double f(const string& s) {
  double sum = 0;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-') {
      sum += 1;
      cnt = 0;
    } else {
      sum += 1.0 / (cnt + 2);
      cnt++;
      max_cnt = max(cnt, max_cnt);
    }
  }
  return sum;
}

int main(void) {
  int N;
  string s;
  cin >> N >> s;
  max_cnt = 0;
  double basetime = f(s);

  double ret;
  cerr << max_cnt << endl;
  ret = basetime - 1.0 + (1.0 / (max_cnt + 2));
  cout << fixed << setprecision(10) << ret << endl;
  return 0;
}