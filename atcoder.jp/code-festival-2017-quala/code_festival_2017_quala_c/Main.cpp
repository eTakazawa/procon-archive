#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  map<char,int> mp;
  for (int i = 0; i < H; i++) {
    cin >> a[i];
    for (int j=0;j<W;j++)
      mp[a[i][j]]++;
  }

  int n4=0,n2=0,n1=0;
  n4 = (H/2) * (W/2);
  if (H%2 == 1) n2 += W / 2;
  if (W%2 == 1) n2 += H / 2;
  n1 = (H%2) * (W%2);


  while(n4) {
    bool in = false;
    for (int i = 0; i < 26; i++) {
      char c = 'a' + i;
      if (mp[c] >= 4) {
        mp[c] -= 4;
        n4--;
        in = true;
      }
    }
    if (!in && n4 > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  while(n2) {
    bool in = false;
    for (int i = 0; i < 26; i++) {
      char c = 'a' + i;
      if (mp[c] >= 2) {
        mp[c] -= 2;
        n2--;
        in = true;
      }
    }
    if (!in && n2 > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  while(n1) {
    bool in = false;
    for (int i = 0; i < 26; i++) {
      char c = 'a' + i;
      if (mp[c] >= 1) {
        mp[c] -= 1;
        n1--;
        in = true;
      }
    }
    if (!in && n1 > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}