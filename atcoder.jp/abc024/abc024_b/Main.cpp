#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
    int n,t;
    cin >> n >> t;
    vector<bool> op(1100001);
    for(int i=0;i<n;i++){
        int a;cin >> a;
        op[a] = true; 
    }
    int ret = 0;
    int tm = 0;
    for(int i=0;i<1100001;i++){
        if(op[i])  {
            tm = t;
        }
        if(tm > 0){
            ret++;
            tm--;
        }
    }
    cout << ret << endl;
	return 0;
}