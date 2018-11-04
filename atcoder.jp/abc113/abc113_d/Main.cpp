#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main(void) {
  int H, W, K;
  cin >> H >> W >> K;
  if (W == 1) {
    cout << 1 << endl;
    return 0;
  }

  long long amida[101][16];
  memset(amida, 0, sizeof(amida));
  amida[0][0] = 1;
  for (int h = 0; h < H; h++) {
    for (int ptn = 0; ptn < (1 << (W-1)); ptn++) {
      bool check = true;
      for (int i = 0; i < W - 2; i++) {
        if (((ptn >> i) & 1) && ((ptn >> (i+1)) & 1)) check = false;
      }
      if (!check) continue;
      
      int p = (ptn << 1);
      for (int i = 0; i < W; i++) {
        if ((p >> i) & 1) {
          amida[h + 1][i - 1] += amida[h][i];
          amida[h + 1][i - 1] %= mod;
        }
        else if ((p >> (i+1)) & 1) {
          amida[h + 1][i + 1] += amida[h][i];
          amida[h + 1][i + 1] %= mod;
        }
        else if (!((p >> i) & 1) && !((p >> (i+1)) & 1)) {
          amida[h + 1][i] += amida[h][i];
          amida[h + 1][i] %= mod;
        }
      }
    }
  }
  for (int i = 0; i < W; i++) {
    cerr << amida[H][i] << " ";
  }cerr << endl;

  cout << amida[H][K - 1] << endl;
  return 0;
}