#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> V(N);
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }
  int ret = -1;
  for (int numTake = 0; numTake <= K; numTake++) {
    if (numTake >= N) {
      int sum = 0;
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i = 0; i < N; i++) {
        sum += V[i];
        pq.push(V[i]);
      }
      for (int i = 0; i < numTake - N; i++) {
        if (pq.empty()) break;
        int m = pq.top();
        pq.pop();
        if (m >= 0) break;
        sum -= m;
      }
      ret = max(ret, sum);
      continue;
    }

    for (int numLeft = 0; numLeft <= numTake; numLeft++) {
      int sum = 0;
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i = 0; i < numLeft; i++) {
        sum += V[i];
        pq.push(V[i]);
      }
      for (int i = 0; i < numTake - numLeft; i++) {
        sum += V[N - 1 - i];
        pq.push(V[N - 1 - i]);
      }

      for (int i = 0; i < K - numTake; i++) {
        if (pq.empty()) break;
        int m = pq.top();
        pq.pop();
        if (m >= 0) break;
        sum -= m;
      } 
      // cerr << sum << endl;
      ret = max(ret, sum);
    }
  }
  cout << ret << endl;
  return 0;
}