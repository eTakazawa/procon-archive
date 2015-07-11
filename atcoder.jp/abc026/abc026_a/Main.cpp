#include <bits/stdc++.h>

using namespace std;

int main(void){
    int A;cin >> A;
    int ret = 0;
    for(int i=0;i<=A;i++){
        ret= max(ret,i*(A-i));
    }
    cout << ret << endl;
    return 0;
}