#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  string s;
  cin>>s;
  
  vector <int> n(4,0);
  for(int i=0;i<N;i++){
    if(s[i]=='1') n[0]++;
    else if(s[i]=='2') n[1]++;
    else if(s[i]=='3') n[2]++;
    else if(s[i]=='4') n[3]++;
  }
  int max=0;
  int min=N+1;
  for(int i=0;i<4;i++){
    if(max<n[i]) max=n[i];
    if(min>n[i]) min=n[i];
  }
  cout<<max<<" "<<min<<endl;
  
  return 0;
}