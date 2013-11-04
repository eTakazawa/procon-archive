#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(void)
{
int n,m;
cin >> n >> m;

if(m>1) cout << m-1 << endl;
else cout << m+1 << endl;

return 0;
}