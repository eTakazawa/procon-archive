#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <utility>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(void){
    int n;
    long long m;
    cin >> n >> m;
    vector<long long>c(n);
    for(int i=0;i<n;i++)
        cin >> c[i];
    
    set<long long>s;
    s.insert(m);
    long long ans = 0;
    
    for(int i=0;i<n;i++){
        set<long long>::iterator it = s.lower_bound(c[i]);
        long long t = abs(c[i]-*it);
        if(it != s.begin()){
            --it;
            t = min(t,abs(c[i]-*it));
        }
        ans += t;
        s.insert(c[i]);
    }
    cout << ans << endl;
    return 0;
}
