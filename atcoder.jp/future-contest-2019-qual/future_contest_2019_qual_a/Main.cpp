#include <bits/stdc++.h>
using namespace std;

const int N = 500;
const int M = 29;
const int L = 300;

typedef pair<int,int> Point;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

inline bool isOut(int x, int y, char board[M][M]) {
  return (x < 0 || y < 0 || x >= M || y >= M || board[y][x] == '#');
}

Point moveByInstruct(char board[M][M], const string& Si, int paths[M][M] = NULL) {
  int dir = 0;
  int x = 14, y = 14;
  for (int i = 0; i < L; i++) {
    if (paths != NULL) paths[y][x]++;

    char c = board[y][x], in = Si[i];
    int rep = 1;
    if (c == '.') rep = 1;
    else if (c == 'D') rep = 2;
    else if (c == 'T') rep = 3;
    else if (c == 'L' && in == 'R') in = 'L';
    else if (c == 'R' && in == 'L') in = 'R'; 

    if (in == 'S') {
      for (int j = 0; j < rep; j++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (isOut(nx, ny, board)) break;
        x = nx;
        y = ny;
      }
    }
    else if (in == 'R') {
      dir = (dir + rep) % 4;
    }
    else if (in == 'L') {
      dir = (dir + 4 - rep) % 4;
    }
    else assert(false);
  }
  return move(Point(x, y));
}

void getStops(char board[M][M], const vector<string>& S, int stopcounts[M][M]) {
  for (int i = 0; i < N; i++) {
    Point p = moveByInstruct(board, S[i]);
    stopcounts[p.second][p.first] += 1;
  }
}
void getPaths(char board[M][M], const vector<string>& S, int paths[M][M]) {
  for (int i = 0; i < N; i++) {
    moveByInstruct(board, S[i], paths);
  }
}

int getStopsScore(int stopcounts[M][M]) {
  int score = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (stopcounts[i][j] == 1) score += 10;
      else if (stopcounts[i][j] == 2) score += 3;
      else if (stopcounts[i][j] == 3) score += 1;
    }
  }
  return score;
}

int getScore(char board[M][M], const vector<string>& S) {
  int stopcounts[M][M] = {0};
  getStops(board, S, stopcounts);
  return getStopsScore(stopcounts);
}

int main(void) {
  int tmp;
  cin >> tmp >> tmp >> tmp;

  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  // 初期解の生成
  char board[M][M];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (i == 0 || i == M - 1 || j == 0 || j == M - 1) board[i][j] = '#';
      else board[i][j] = 'L';
    }
  }
  // pathsの計算
  int paths[M][M] = {0};
  getPaths(board, S, paths);

  // pathsが多いところを変える
  string mapchip = ".#DTLR";
  int chipcount = (int)mapchip.size();
  
  int prevscore = getScore(board, S);
  char prevboard[M][M];
  memcpy(prevboard, board, sizeof(board));

  auto start = chrono::system_clock::now();
  while (true) {
    auto dur = chrono::system_clock::now() - start;
    if (chrono::duration_cast<std::chrono::milliseconds>(dur).count() >= 2900) break; 

    int stops[M][M] = {0};
    getStops(board, S, stops);
    int max_stops = -1, max_i, max_j;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        if (max_stops < stops[i][j]) {
          max_stops = stops[i][j];
          max_i = i;
          max_j = j;
        }
      }
    }

    if (rand() % 4 == 0) {
      board[max_i][max_j] = '#';
    }
    for (int i = 0; i < 4; i++) {
      int ni = max_i + dy[i], nj = max_j + dx[i];
      if (ni < 1 || nj < 1 || ni >= M - 1 || nj >= M - 1) continue;
      board[ni][nj] = mapchip[rand() % chipcount];
    }

    int score = getScore(board, S);
    if (prevscore < score) {
      prevscore = score;
      memcpy(prevboard, board, sizeof(board));
    } else {
      memcpy(board, prevboard, sizeof(board));
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }

  return 0;
}
