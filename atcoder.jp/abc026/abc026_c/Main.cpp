#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<vector<int>> buka(200);
    vector<int> kyuryo(200);

    for(int i=0;i<n-1;i++){
        int b;cin >> b;
        b--;
        buka[b].push_back(i+1);
    }

    for(int i=n;i>=0;i--){
        if(buka[i].size() == 0)kyuryo[i] = 1;
        else{
            int ma=-1,mi=1000000000;
            for(int j=0;j<buka[i].size();j++){
                ma = max(ma,kyuryo[buka[i][j]]);
                mi = min(mi,kyuryo[buka[i][j]]);
            }
            kyuryo[i] = ma + mi + 1;
        }
    }
    cout << kyuryo[0] << endl;

    return 0;
}