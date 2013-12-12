#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<cmath>
 
using namespace std;
 
int main(void){
int N,K;
double C=0;
vector<int> R;
 
cin >> N >> K;
for(int i=0;i<N;i++){
int hoge;
cin >> hoge;
R.push_back(hoge);
}
 
sort(R.begin(),R.end());
for(int i=N-K,j=K;i<N;i++,j--){
C+=R[i]/pow(2,j);
}
printf("%f\n",C);
return 0;
}