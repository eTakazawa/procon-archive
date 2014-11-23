#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    int cnt = 0,sum = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 0)continue;
        else{
            cnt++;
            sum += a[i];
        }
    }
    cout << ceil(1. * sum / cnt) << endl;
    
    return 0;
}
