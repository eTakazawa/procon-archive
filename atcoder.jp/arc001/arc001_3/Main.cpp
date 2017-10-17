#include <iostream>
#include <vector>
#include <string>

using namespace std;

int di[] = {-1,-1,-1, 0,0, 1,1,1};
int dj[] = {-1, 0, 1,-1,1,-1,0,1};
bool check(const vector<string>& c) {
  for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) {
    if (c[i][j] == 'Q') {
      for (int k = 1; k <= 8; k++) for (int d = 0; d < 8; d++) {
        int ni = i + di[d] * k;
        int nj = j + dj[d] * k;
        if (ni < 0 || nj < 0 || ni >= 8 || nj >= 8) continue;
        if (c[ni][nj] == 'Q') return false;
      }
    }
  }
  return true;
}

void show(const vector<string>& c) {
  for (int i = 0; i < 8; i++) {
    cout << c[i] << endl;
  }
}

vector<string> ret;
bool dfs(vector<string>& c, int n) {
  if (n == 8) {
    if (check(c)) {
      ret = c;
      return true;
    }
    return false;
  }

  for (int i = 0; i < 8; i++) {
    if (c[n][i] == 'Q') {
      return dfs(c, n+1);
    }
  }

  bool ret = false;
  for (int i = 0; i < 8; i++) {
    c[n][i] = 'Q';
    ret |= dfs(c, n+1);
    c[n][i] = '.';
  }
  return ret;
}

int main(void) {
  vector<string> c(8);
  for (int i = 0; i < 8; i++) {
    cin >> c[i];
  }
  if (dfs(c ,0)) {
    show(ret);
  } else {
    cout << "No Answer" << endl;
  }

  return 0;
}