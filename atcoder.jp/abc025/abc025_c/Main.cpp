#include <bits/stdc++.h>
using namespace std;

int calcScore(vector<vector<int>>& board,vector<vector<int>>& b,vector<vector<int>>& c){
	int tyoku = 0 ,nao = 0;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			if(board[i][j] == board[i+1][j])
				tyoku += b[i][j];
			else
				nao += b[i][j];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(board[i][j] == board[i][j+1])
				tyoku += c[i][j];
			else
				nao += c[i][j];
		}
	}
	return tyoku - nao;
}

int dfs(int t,vector<vector<int>>& board,vector<vector<int>>& b,vector<vector<int>>& c){
	if(t == 9)return calcScore(board,b,c);
	int ret = -1e9;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j] == -1){
				board[i][j] = t % 2;
				ret = max(ret,dfs(t+1,board,b,c));
				board[i][j] = -1;
			}
		}
	}
	return -ret;
}

int main(void){
	vector<vector<int>> b(2,vector<int>(3));
	vector<vector<int>> c(3,vector<int>(2));
	int sum = 0;
	for(int i=0;i<2;i++)for(int j=0;j<3;j++){
		cin >> b[i][j];
		sum += b[i][j];
	}
	for(int i=0;i<3;i++)for(int j=0;j<2;j++){
		cin >> c[i][j];
		sum += c[i][j];
	}

	vector<vector<int>> board(3,vector<int>(3,-1));
	int diff = dfs(0,board,b,c);
	cout << (sum-diff)/2 << endl << (sum+diff)/2 << endl;

	return 0;
}