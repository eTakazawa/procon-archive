#include <bits/stdc++.h>
using namespace std;

double noudo(int a, int b) {
  return (100. * b) / (a + b);
}

int main(void) {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  double maxnoudo = 0.0;
  int sugarwater = -1, sugar;
  for (int i = 0; i <= 30; i++) for (int j = 0; j <= 30; j++) {
    if (100*a*i + 100*b*j > f) continue;
    for (int l = 0; l <= 100; l++) for (int m = 0; m <= 100; m++) {
      if (100*a*i + 100*b*j + c*l + d*m > f) continue;
      if ((a*i + b*j) * e < c*l + d*m ) continue;
      double nownoudo = noudo(100*a*i + 100*b*j, c*l + d*m);
      if (nownoudo > maxnoudo) {
        maxnoudo = nownoudo;
        sugarwater = 100*a*i + 100*b*j + c*l + d*m;
        sugar = c*l + d*m;
      }
    }
  }
  if (sugarwater == -1) cout << 100*a << " " << 0 << endl;
  else cout << sugarwater << " " << sugar << endl;
  return 0;
}