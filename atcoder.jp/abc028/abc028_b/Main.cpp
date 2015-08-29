#include <iostream>
#include <vector>
using namespace std;
int main(void){
string s;
cin >> s;
vector<int> cnt(6);
for(int i =0;i<s.size();i++){
cnt[s[i] - 'A']++;
}
for(int i=0;i<5;i++)
cout << cnt[i] <<" ";
cout << cnt[5] << endl;
return 0;
}