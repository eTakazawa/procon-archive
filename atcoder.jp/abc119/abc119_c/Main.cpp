#include <bits/stdc++.h>
using namespace std;

int N;
int ret;
vector<int> tgt, l;
void dfs(int i, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4) {
  if (i == N) {
    int cost = 0, a = 0, b = 0, c = 0;
    for (auto vv : v1) {
      a += vv;
      cost += 10;
    }
    for (auto vv : v2) {
      b += vv;
      cost += 10;
    }
    for (auto vv : v3) {
      c += vv;
      cost += 10;
    }
    cerr << a << " " << b << " " << c << endl;
    if (v1.size() == 0) return;
    if (v2.size() == 0) return;
    if (v3.size() == 0) return;
    cost -= 30;
  
    cost += abs(tgt[0] - a);
    cost += abs(tgt[1] - b);
    cost += abs(tgt[2] - c);
    ret = min(ret, cost);
    return;
  }
  v1.push_back(l[i]);
  dfs(i + 1, v1, v2, v3, v4);
  v1.pop_back();

  v2.push_back(l[i]);
  dfs(i + 1, v1, v2, v3, v4);
  v2.pop_back();

  v3.push_back(l[i]);
  dfs(i + 1, v1, v2, v3, v4);
  v3.pop_back();

  v4.push_back(l[i]);
  dfs(i + 1, v1, v2, v3, v4);
  v4.pop_back();
}

int main(void) {
  cin >> N;
  ret = 1e9;
  tgt.resize(3);
  l.resize(N);
  cin >> tgt[0] >> tgt[1] >> tgt[2];
  for (int i = 0; i < N; i++) {
    cin >> l[i];
  }
  cerr << 'e' << endl;
  vector<int> v1,v2,v3,v4;
  dfs(0, v1, v2, v3, v4);
  cout << ret << endl;
  return 0;
}