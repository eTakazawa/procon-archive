#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;
  int board[100][100];
  memset(board, 0, sizeof(board));
  swap(A,B);
  for (int i = 0; i < A - 1; i++) {
    int r = 4 * (i % 25) + 1;
    int c = 4 * (i / 25) + 1;
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (di == 0 && dj == 0) continue;
        int nr = r + di, nc = c + dj;
        board[nr][nc] = 1;
      }
    }
    B--;
  }
  cerr << B << endl;
  if (B > 0) {
    for (int i = 0; i < B; i++) {
      int r = 2 * (i % 50);
      int c = 99 - 2 * (i / 50);
      board[r][c] = 1;
    }
  }
  if (B < 0) {
    B = -B;
    int i = 0;
    while (B) {
      int r = 4 * (i / 2 % 25) + 1;
      int c = 4 * (i / 2 / 25) + 1;
      if (i % 2 == 0) {
        board[r + 2][c - 1] = 1;
        board[r + 2][c] = 1;
        board[r + 2][c + 1] = 1;
        if (r != 97 && c == 1) B--;
        // if (r != 97 && c == 1)
        //  cerr << r << " " << c << endl;
      } else {
        board[r - 1][c + 2] = 1;
        board[r][c + 2] = 1;
        board[r + 1][c + 2] = 1;
        board[r + 2][c + 2] = 1;
        if (i / 2 + 25 <= A) B--;
        // if (i / 2 + 25 <= A)
        //   cerr << r << " " << c << endl;
      }
      i++;
    }
  }

  cout << "100 100" << endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cout << (board[i][j] ? '.' : '#');
    }
    cout << endl;
  }

  return 0;
}