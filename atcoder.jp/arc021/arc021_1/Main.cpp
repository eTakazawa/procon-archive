#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int a[4]={-1,0,1,0};
int b[4]={0,1,0,-1};

int main(){
	int tile[6][6];
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)tile[i][j]=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin >> tile[i][j];
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			for(int k=0;k<4;k++){
				if(tile[i][j]==tile[i+a[k]][j+b[k]]){
					cout << "CONTINUE" << endl;
					return 0;
				}
			}
		}
	}
	cout << "GAMEOVER" << endl;
}
