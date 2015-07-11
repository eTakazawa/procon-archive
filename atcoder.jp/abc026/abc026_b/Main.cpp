#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<double> r(n);
    for(int i=0;i<n;i++){
        cin >> r[i];
    }
    sort(begin(r),end(r),greater<double>());
    double ret = 0;
    for(int i=0;i<n;i++){
        if(i%2==0)ret += r[i]*r[i]*M_PI;
        else ret -= r[i]*r[i]*M_PI;
    }
    cout << fixed << setprecision(10) << ret << endl;

    return 0;
}