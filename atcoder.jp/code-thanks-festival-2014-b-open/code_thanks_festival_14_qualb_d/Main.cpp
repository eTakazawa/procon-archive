#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

int cnt[2000];
int main(void){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++){
        for(int j=1;j<=1000;j++){
            if(j*a[i] > t)break;
            else cnt[j*a[i]]++;
        }
    }
    int ans = 0;
    for(int i=0;i<=t;i++){
        ans = max(ans,cnt[i]);
    }
    cout << ans << endl;

    return 0;
}
