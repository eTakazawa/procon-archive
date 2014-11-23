#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std;

vector<vector<int> >t;

void dfs(int a,int k,int x,int n){
    if(a>=n){
        if(x==0){
            cout << "Found" << endl;
            exit(0);
        }
        return;
    }
    for(int i=0;i<k;i++){
        dfs(a+1,k,x^t[a][i],n);
    }
}

int main(void){
    int n,k;
    cin >> n >> k;
    t.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int a;cin >> a;
            t[i].push_back(a);
        }
    }
    dfs(0,k,0,n);
    cout << "Nothing" << endl;
    
    return 0;
}
