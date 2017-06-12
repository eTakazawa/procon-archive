#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int main(void) {
  int N;
  cin >> N;
  vector<int> s(N);
  for(int i=0;i<N;i++){
    cin >> s[i];
  }


  dp[0] = 1;
  for(int t=0;t<N;t++){
    for(int i=10000;i>=0;i--){
      if(i - s[t] < 0)continue;
      if(dp[i - s[t]]) dp[i] = 1;
    }
  }

  for(int i=10000;i>=0;i--){
    if(dp[i] && i % 10 != 0){
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}