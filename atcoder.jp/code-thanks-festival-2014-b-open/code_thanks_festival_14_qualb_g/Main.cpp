#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;


//turn数,残り何個,何個取れるか
int memo[2][550][1001];
int dfs(int turn,int n,int p){ 
	if(n <= 0)return (turn%2==0 ? false : true);
	
	if(memo[turn%2][n][p] != -1)
		return memo[turn%2][n][p];

	bool ret;
	if(turn%2 == 0){
		ret = false;
		for(int i=1;i<=p;i++){
			ret |= dfs(turn+1,n-i,i+1);
		}

	}else{
		ret = true;
		for(int i=1;i<=p;i++){
			ret &= dfs(turn+1,n-i,i+1);
		}
	}
	if(ret)memo[turn%2][n][p] = 1;
	else memo[turn%2][n][p] = 0;
	return ret;
}

int main(void){
	int n,p;
	cin >> n >> p;
	memset(memo,-1,sizeof(memo));
	if(dfs(0,n,p))
		cout << "first" << endl;
	else
		cout << "second" << endl;

	return 0;
}