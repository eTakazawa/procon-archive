#include <bits/stdc++.h>
using namespace std;

long long div12(long long H, long long W) {
  long long ret = 1e18;
  for(int i=1;i<H;i++){
    long long p1 = i * W;
    
    int w1,w2;
    if(W%2==0){
      w1 = w2 = W/2;
    } else {
      w1 = W/2;
      w2 = W/2 + 1;
    }
    long long p2 = (H-i) * w1;
    long long p3 = (H-i) * w2;
    ret = min(ret,max(max(p1,p2),p3) - min(min(p1,p2),p3));
  }
  return ret;
}
long long div3(long long H, long long W){
  long long h1,h2,h3;
  if(H%3==0){
    h1 = h2 = h3 = H/3;
  }else if(H%3==1){
    h1 = h2 = H/3;
    h3 = H/3 + 1;
  }else{
    h1 = H/3;
    h2 = H/3 + 1;
    h3 = H/3 + 1;
  }
  long long p1 = h1*W;
  long long p2 = h2*W;
  long long p3 = h3*W;
  return max(max(p1,p2),p3) - min(min(p1,p2),p3);
}

int main(void) {
  long long H,W;
  cin >> H >> W;  

  long long ret = 1e18;;
  ret = min(div12(H,W),div12(W,H));
  ret = min(ret,div3(H,W));
  ret = min(ret,div3(W,H));

  cout << ret << endl;
  return 0;
}