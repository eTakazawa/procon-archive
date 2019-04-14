#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  string s;
  cin >> s;

  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }

  vector<int> vec, sta;
  int cnt = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      vec.push_back(cnt);
      sta.push_back(s[i - 1] - '0');
      cnt = 1;
    } else {
      cnt++;
    }
  }
  vec.push_back(cnt);
  sta.push_back(s[s.size() - 1] - '0');

  int k = 0, sum = 0;
  int ret = 0;
  int j = 0;
  for (int i = 0; i < vec.size(); i++) {
    // cerr << i << " : " << vec[i] << endl;
    // cerr << "sum : " << sum << endl;
    if (sta[i] == 0) k++;
    while (K + 1 == k && j < vec.size()) {
      if (sta[j] == 0) k--;
      sum -= vec[j];
      j++;
    }

    sum += vec[i];
    ret = max(ret, sum);
  }
  cout << ret << endl;

  return 0;
}