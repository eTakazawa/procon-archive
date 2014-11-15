#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <utility>
#include <climits>

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] > i+1){
            cnt += abs(a[i]-i-1)*2;
        }else if(a[i] < i+1){
            cnt -= abs(a[i]-i-1);
        }
        
    }
    
    cout << cnt << endl;
    
    return 0;
}
