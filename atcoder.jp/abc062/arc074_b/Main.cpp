#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> a(3 * N);
  for (int i = 0; i < 3 * N; i++) {
    cin >> a[i];
  }

  vector<long long> m_f(N + 1);
  {
    long long sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
      sum += a[i];
      pq.push(a[i]);
    }
    m_f[0] = sum;
    for (int i = N; i < 2 * N; i++) {
      int m_in_sum = pq.top();
      if (m_in_sum < a[i]) {
        sum -= m_in_sum;
        sum += a[i];
        pq.pop();
        pq.push(a[i]);
      }
      m_f[i + 1 - N] = sum;
    }
  }

  vector<long long> m_b(N + 1);
  {
    priority_queue<int> pq;
    long long sum = 0;
    for (int i = 2*N; i < 3*N; i++) {
      sum += a[i];
      pq.push(a[i]);
    }
    m_b[N] = sum;
    for (int i = 2 * N - 1; i >= N; i--) {
      int m_in_sum = pq.top();
      if (m_in_sum > a[i]) {
        sum -= m_in_sum;
        sum += a[i];
        pq.pop();
        pq.push(a[i]);
      }
      m_b[i - N] = sum;
    }
  }

  long long ret = -1e18;
  for (int i = 0; i <= N; i++) {
    ret =  max(ret, m_f[i] - m_b[i]);
  }
  cout << ret << endl;

  return 0;
}