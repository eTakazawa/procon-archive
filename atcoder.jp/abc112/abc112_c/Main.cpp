#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> x(N), y(N), h(N);
  vector<tuple<int,int,int>> v;
  bool zero = false;
  for (int i = 0; i < N; i++) {
    int tmpx, tmpy, tmph;
    cin >> tmpx >> tmpy >> tmph;
    v.emplace_back(tmph, tmpx, tmpy);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    h[i] = get<0>(v[i]);
    x[i] = get<1>(v[i]);
    y[i] = get<2>(v[i]);
  }

  for (int cx = 0; cx <= 100; cx++) for (int cy = 0; cy <= 100; cy++) {
    int ch = -1;
    bool ok = true;
    for (int i = 0; i < N; i++) {
      if (ch == -1) {
        ch = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
      } else {
        if (h[i] == 0) {
          int newch = ch - (abs(cx - x[i]) + abs(cy - y[i]));
          if (newch > 0) {
            ok = false;
            break;
          }
        } else {
          int newch = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
          if (newch != ch) {
            ok = false;
            break;
          }
        }
      }
    }
    if (ok) {
      cout << cx << " " << cy << " " << ch << endl;
      break;
    }
  }

  return 0;
}