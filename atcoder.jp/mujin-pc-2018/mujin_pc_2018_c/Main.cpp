#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  std::vector<string> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  vector<vector<int>> sum1(N, vector<int>(M));
  vector<vector<int>> sum2(N, vector<int>(M));
  vector<vector<int>> sum3(N, vector<int>(M));
  vector<vector<int>> sum4(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < M; j++) {
      if (v[i][j] == '.' && v[i][j - 1] == '.')
      sum1[i][j] = sum1[i][j - 1] + 1;
    }
    for (int j = M - 2; j >= 0; j--) {
      if (v[i][j] == '.' && v[i][j + 1] == '.')
      sum2[i][j] = sum2[i][j + 1] + 1;
    }
  }
  for (int j = 0; j < M; j++) {
    for (int i = 1; i < N; i++) {
      if (v[i][j] == '.' && v[i - 1][j] == '.')
      sum3[i][j] = sum3[i - 1][j] + 1;
    }
    for (int i = N - 2; i >= 0; i--) {
      if (v[i][j] == '.' && v[i + 1][j] == '.')
      sum4[i][j] = sum4[i + 1][j] + 1;
    }
  }

  long long sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      sum += sum1[i][j] * sum3[i][j];
      sum += sum2[i][j] * sum4[i][j];
      sum += sum3[i][j] * sum2[i][j];
      sum += sum4[i][j] * sum1[i][j];
    }
  }
  cout << sum << endl;


  return 0;
}