#include <bits/stdc++.h>
using namespace std;

struct Point{
  int x,y;
  Point(int x,int y) :x(x),y(y){}
};

int main(void) {
  int H,W,A,B;
  cin >> H >> W >> A >> B;
  vector<string> m(H);
  for (int i = 0; i < H; i++)
    cin >> m[i];

  long long ret = 0;
  for (int i = 0; i < H/2; i++) {
    for (int j = 0; j < W/2; j++) {
      if (m[i][j] == '.') continue;
      if (m[i][W-1-j]=='S' && m[H-1-i][j]=='S' && m[H-1-i][W-1-j]=='S') {
        ret += max(A, B) + (A + B);
        m[H-1-i][W-1-j] = m[H-1-i][j] = m[i][W-1-j] = m[i][j] = '.';
      }
    }
  }
  bool amari_yon = false;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (m[i][j] == 'S') amari_yon = true;
    }
  }

  // 東西の和
  long long touzai = 0;
  bool amari_touzai = false;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W/2; j++) {
      if (m[i][j] == '.') continue;
      if (m[i][W-1-j]=='S') {
        touzai += B;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (m[i][j] == 'S' && m[i][W-1-j]=='.') {
        amari_touzai = true;
      }
    }
  }
  // 南北の和
  long long nanboku = 0;
  bool amari_nanboku = false;
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H/2; i++) {
      if (m[i][j] == '.') continue;
      if (m[H-1-i][j]=='S') {
        nanboku += A;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (m[i][j] == 'S' && m[H-1-i][j]=='.') {
        amari_nanboku = true;
      }
    }
  }

  cerr << ret << " " << nanboku << " " << touzai << endl;

  if (nanboku == 0 && touzai == 0) {
    if (amari_yon)
      cout << ret + A + B << endl;
    else
      cout << ret << endl;
    return 0;
  }

  long long ret1 = 0, ret2 = 0;
  ret1 = ret + touzai + A + B;
  if (!amari_touzai) {
    ret1 -= B;
  }

  ret2 = ret + nanboku + A + B;
  if (!amari_nanboku) {
    ret2 -= A;
  }
  cerr << ret1 << " " << ret2 << endl;
  cout << max(ret1, ret2) << endl;

  return 0;
}