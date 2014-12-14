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

int main(void){
    int n;
    cin >> n;
    vector<int> v(n),f(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    for(int i=0;i<n;i++)
        cin >> f[i];
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(v[i] < f[i] * 2)cnt++;
    }
    cout << cnt << endl;
    return 0;
}
