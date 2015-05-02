#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w;
vector<string> s;
int memo[101][101][2];
bool dfs(int r,int c,int p){
	//cout << r << " " << c << " " << p << endl;
	if(r==h-1&&(c==w-1 || s[r][c+1]=='#'))return (p%2==1);
	if(c==w-1&&(r==h-1 || s[r+1][c]=='#'))return (p%2==1);
	if(memo[r][c][p%2] != -1)return memo[r][c][p%2];
	bool res = false;
	if(p%2 == 0){
		res = false;
		if(r<h-1 && s[r+1][c]=='.')res |= dfs(r+1,c,p+1);
		if(c<w-1 && s[r][c+1]=='.')res |= dfs(r,c+1,p+1);
		if(r<h-1&&c<w-1 && s[r+1][c+1]=='.')res |= dfs(r+1,c+1,p+1);
	}else{
		res = true;
		if(r<h-1 && s[r+1][c]=='.')res &= dfs(r+1,c,p+1);
		if(c<w-1 && s[r][c+1]=='.')res &= dfs(r,c+1,p+1);
		if(r<h-1&&c<w-1 && s[r+1][c+1]=='.')res &= dfs(r+1,c+1,p+1);
	}
	return memo[r][c][p%2] = (res?1:0);
}

int main(void){
	cin >> h >> w;
	s.resize(h);
	int r,c;
	for(int i=0;i<h;i++){
		cin >> s[i];
	}
	memset(memo,-1,sizeof(memo));
	for(int i=0;i<h;i++){
		for(int j=0;j<s[i].size();j++){
			if(s[i][j] == 'o'){
				r = i;
				c = j;
				break;
			}
		}
	}
	cout << (dfs(r,c,0)==1?"First":"Second") << endl;


	return 0;
}
