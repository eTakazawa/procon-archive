#include<iostream>
using namespace std;
int main(){
int n,i;
cin >> n;
for(i=n-1;i>0;i--)
if(n%i==0)break;
if(i==1)cout << "YES" << endl;
else cout << "NO" << endl;
return 0;
}