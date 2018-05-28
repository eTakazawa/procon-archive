#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  map<char,long long> dic;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    dic[s[0]]++;
  }

  string s = "MARCH";
  long long ret = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        ret += dic[s[i]] * dic[s[j]] * dic[s[k]];
      }
    }
  }
  cout << ret << endl;
  return 0;
}