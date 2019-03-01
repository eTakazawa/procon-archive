#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<double> x(N);
  vector<string> u(N);
  double sum = 0.0;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> u[i];
    if (u[i] == "JPY") sum += x[i];
    else sum += x[i] * 380000;
  }
  cout << fixed << setprecision(10) << sum << endl;

  return 0;
}