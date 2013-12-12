#include<iostream>
#include<string>
using namespace std;
int main(void){
string S,T;
string A="atcoder";
int cnt=0;
cin >> S;
cin >> T;
 
for(int i=0;i<S.size();i++){
if(S[i]==T[i]){
cnt++;
}
else{
if(S[i]=='@'){
for(int j=0;j<A.size();j++)
if(T[i]==A[j])
cnt++;
}
if(T[i]=='@'){
for(int j=0;j<A.size();j++)
if(S[i]==A[j])
cnt++;
}
}
}
 
if(cnt==S.size())cout << "You can win" << endl;
else cout << "You will lose" << endl;
 
return 0;
}