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
 
int vv[51][51];
int used[51][51];
 
bool dfs(int r,int c,int rg,int cg){
    if(vv[r][c] == 0)return false;
    if(r==rg && c==cg )return true;
 
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i*j!=0 || used[r+i][c+j] )continue;
            used[r][c] = 1;
            if(dfs(r+i,c+j,rg,cg))return true;
        }
    }
    return false;
}
 
int main(void){
    int r,c,rs,cs,rg,cg;
    cin >> r >> c;
    cin >> rs >> cs >> rg >> cg;
    int n;
    cin >> n;
 
    for(int i=0;i<n;i++){
        int rr,cc,h,w;
        cin >> rr >> cc >> h >> w;
        for(int i=rr;i<rr+h;i++){
            for(int j=cc;j<cc+w;j++){
                vv[i][j] = 1;
            }
        }
    }
 
    if(dfs(rs,cs,rg,cg))cout << "YES" << endl;
    else cout << "NO" <<endl;
 
    return 0;
}