#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

vector<int> A,B;
int memo[10003][52][52];
int dfs(int n,int k,int w,int K,int N,int W){
    if(k>K || w>W){
        return -10000;
    }
    if(n>=N){
        return 0;
    }
    if(memo[w][n][k]!=-1)return memo[w][n][k];
    int ret = 0;
    ret = max(dfs(n+1,k+1,w+A[n],K,N,W)+B[n] ,dfs(n+1,k,w,K,N,W));
    return memo[w][n][k] = ret;
}

int main(void){
    int W,N,K;
    cin >> W >> N >> K;
    A.resize(N);B.resize(N);
    for(int i=0;i<N;i++)
        cin >> A[i] >> B[i];
    
    memset(memo,-1,sizeof(memo));
    int ret = dfs(0,0,0,K,N,W);
    cout << (ret<0 ? 0 : ret) << endl;
    
    return 0;
}
