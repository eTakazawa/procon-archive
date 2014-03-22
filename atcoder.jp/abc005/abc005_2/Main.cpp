#include<iostream>
using namespace std;
int main(){
int t,n,ret=100;
cin >> n;
for(int i=0;i<n;i++){
cin >> t;
ret = min(ret,t);
}
cout << ret << endl;
return 0;
}