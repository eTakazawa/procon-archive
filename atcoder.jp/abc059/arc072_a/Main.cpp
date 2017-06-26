#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> orga(N);
  for(int i=0;i<N;i++){
    cin >> orga[i];
  }

  long long sum = 0;
  long long cnt = 0;
  long long mincnt = 1e18;
  for(int sign=0;sign<=1;sign++){
    vector<long long> a(orga);
    cnt = 0;
    sum = 0;
    for(int i=0;i<N;i++){
      if(i == 0){
        if(sign == 0 && a[0] >= 0){
          long long diff = abs(a[0]) + 1;
          a[i] -= diff;
          cnt += diff;
        }
        if(sign == 1 && a[0] <= 0){
          long long diff = abs(a[0]) + 1;
          a[i] += diff;
          cnt += diff;
        }
      }
      else if(sum + a[i] == 0){
        if(sum < 0){
          cnt++;
          a[i]++;
        }else if(sum > 0){
          cnt++;
          a[i]--;
        }
      }
      else if(sum < 0 && sum + a[i] < 0){
        long long diff = abs(sum + a[i]) + 1;
        cnt += diff;
        a[i] += diff;
      }
      else if(sum > 0 && sum + a[i] > 0){
        long long diff = abs(sum + a[i]) + 1;
        cnt += diff;
        a[i] -= diff;
      }
      sum += a[i];
    }
    mincnt = min(cnt,mincnt);
    for(int i=0;i<N;i++){
      cerr << a[i] << " ";
    }cerr << endl;
  }
  cout << mincnt << endl;
  return 0;
}