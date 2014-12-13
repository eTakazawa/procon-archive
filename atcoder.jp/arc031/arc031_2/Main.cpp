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

int used[12][12];
char a[12][12];
char b[12][12];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void bfs(int x,int y){
    queue<int>qx,qy;
    qx.push(x);qy.push(y);
    while(!qx.empty()){
        int x = qx.front();qx.pop();
        int y = qy.front();qy.pop();
        b[y][x] = 'x';
        for(int i=0;i<4;i++){
            if(b[y+dy[i]][x+dx[i]]=='o'){
                qx.push(x+dx[i]);
                qy.push(y+dy[i]);
            }
        }
    }
}

bool check(int y,int x){
    memcpy(b,a,sizeof(b));
    bfs(y,x);
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(b[i][j] == 'o')return false;
        }
    }
    return true;
}

int main(void){
    for(int i=0;i<=11;i++){
        for(int j=0;j<=11;j++){
            if(i==0||j==0||i==11||j==11)a[i][j] = 'x';
            else cin >> a[i][j];
        }
    }

    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(check(i,j)){
                 cout << "YES" << endl;
                 return 0;
            }
        }
    }
    cout << "NO" <<endl;
    return 0;
}
