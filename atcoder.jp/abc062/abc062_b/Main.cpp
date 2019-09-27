#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  string s;
  string edge(W + 2, '#');
  cout << edge << endl;
  for (int i = 0; i < H; i++) {
    cout << "#";
    cin >> s;
    cout << s;
    cout << "#" << endl;
  }
  cout << edge << endl;

  return 0;
}