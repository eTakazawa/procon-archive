#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;

  int used[201];
  queue<int> q;
  
  memset(used, 0, sizeof(used));
  q.push(A);

  int d[] = {1,-1,5,-5,10,-10};
  const int geta = 50;
  for (int t = 0; true; t++) {
    queue<int> nextq;
    while (!q.empty()) {
      int now = q.front();q.pop();
      if (now == B) {
        cout << t << endl;
        return 0;
      }
      for (int i = 0; i < 6; i++) {
        int next = now + d[i];
        if (next < -50 || next > 50) continue;
        if (used[next + geta]) continue;
        nextq.push(next);
        used[next + geta] = 1;
      }
    }
    q = nextq;
  }
  
  return 0;
}