#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
    int n,d,k;
    cin >> n >> d >> k;
    vector<int> L(d),R(d);
    for(int i=0;i<d;i++){
        cin >> L[i] >> R[i];
    }
    vector<int> S(k),T(k);
    for(int i=0;i<k;i++){
        cin >> S[i] >> T[i];
    }

    for(int i=0;i<k;i++){
        int l = S[i],r = S[i];
        for(int j=0;j<d;j++){
            // cout << l << " " << r << endl;
            if(l <= R[j])
                l = min(l,L[j]);
            if(r >= L[j]){
                r = max(r,R[j]);
            }

            if(S[i] < T[i]){
                if(r >= T[i]){
                    cout << j+1 << endl;
                    break;
                }
            }else{
                if(l <= T[i]){
                    cout << j+1 << endl;
                    break;
                }
            }
        }
    }

	return 0;
}