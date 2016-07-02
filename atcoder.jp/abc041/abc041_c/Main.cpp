#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
    	int tmp;cin >> tmp;
    	a.emplace_back( -tmp, i);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
    	cout << a[i].second+1 << endl;
    }

    return 0;
}