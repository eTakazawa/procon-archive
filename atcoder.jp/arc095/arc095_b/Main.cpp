#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int maxelemid = max_element(a.begin(), a.end()) - a.begin();
  int maxelem = *max_element(a.begin(), a.end());

  long long half, half2;
  half = (maxelem + 1) / 2;
  if ((maxelem + 1) % 2 == 0) half2 = (maxelem + 1) / 2 - 1;

  long long difmin = 1e10;
  long long difminid = -1;
  for (int i = 0; i < n; i++) {
    if (i == maxelemid) continue;
    long long diff = abs(a[i] - half);
    if ((maxelem + 1) % 2 == 0) diff = min(diff, abs(a[i] - half2));
    if (difmin > diff) {
      difmin = diff;
      difminid = i;
    }
  }
  cout << maxelem << " " << a[difminid] << endl;
  return 0;
}