#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int A, B, K;
  cin >> A >> B >> K;

  vector<int> div;
  for (int i = 1; i <= min(A, B); i++) {
    if (A % i == 0 && B % i == 0) {
      div.push_back(i);
    }
  }
  cout << div[div.size() - K] << endl;

  return 0;
}