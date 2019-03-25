#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string b;
  cin >> b;
  for (auto c : b) {
    if (c == 'A') cout << "T";
    if (c == 'T') cout << "A";
    if (c == 'G') cout << "C";
    if (c == 'C') cout << "G";
  }
  cout << endl;
  return 0;
}