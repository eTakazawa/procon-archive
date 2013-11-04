#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
 
using namespace std;
 
int main(void)
{
int n;
char f[101][9];
cin >> n;
for(int i=0; i < n; i++)
cin >> f[i];
for(int i=0; i < 9;i++)
f[n][i] = '.';


int cnt=0;
 
for(int i=0; i<n; i++)
{
for(int j=0; j<9; j++)
{
if(f[i][j] == 'x')
cnt++;
else if((f[i+1][j] == '.' || f[i+1][j] == 'x') && f[i][j] == 'o')
cnt++;
}
}
cout << cnt << endl;
return 0;
}