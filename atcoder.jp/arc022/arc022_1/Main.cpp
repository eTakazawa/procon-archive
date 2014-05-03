#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<cctype>
#define INF 99999999

using namespace std;

int vx[4]={-1,0,1,0};
int vy[4]={0,1,0,-1};
int board[100][100]={0};

int main(){
	string s;
	cin >> s;
	bool f1=false,f2=false,f3=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='I' || s[i]=='i')f1 = true;
		if((s[i]=='C' || s[i]=='c') &&f1)f2=true;
		if((s[i]=='T' || s[i]=='t') && f1 && f2)f3 =true;
	}
	if(f1&&f2&&f3)cout << "YES" << endl;
	else cout << "NO" << endl;
}