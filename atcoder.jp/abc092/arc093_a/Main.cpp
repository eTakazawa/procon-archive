#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A;
  A.push_back(0);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  A.push_back(0);

  long long orgdist = 0;
  for (int i = 1; i <= N + 1; i++) {
    orgdist += abs(A[i] - A[i-1]);
  }

  for (int i = 1; i <= N; i++) {
    if (A[i-1] <= A[i] && A[i] <= A[i+1] ||
        A[i+1] <= A[i] && A[i] <= A[i-1]) {
      cout << orgdist << endl;
    } else if (
      A[i-1] <= A[i] && A[i+1] <= A[i-1] ||
      A[i] <= A[i-1] && A[i-1] <= A[i+1]
      ) {
      cout << orgdist - 2*abs(A[i] - A[i-1]) << endl;
    } else {
      cout << orgdist - 2*abs(A[i+1] - A[i]) << endl;
    }
  }

  return 0;
}