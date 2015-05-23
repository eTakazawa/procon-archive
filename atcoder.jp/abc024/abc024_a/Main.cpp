#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
    ll a,b,c,k;
    ll s,t;
    cin >> a >> b >> c >> k;
    cin >> s >> t;
    if(s+t >= k)cout << a*s+b*t-(s+t)*c << endl;
    else cout << a*s+b*t << endl;

	return 0;
}