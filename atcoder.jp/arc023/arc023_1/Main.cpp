#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cctype>
#include<vector>
#include<cstring>
#include<utility>
#define INF 99999999
using namespace std;

bool board[100][100];

int main(){
	int y,m,d;
	cin >> y >> m >> d;
	if(m<3){
		m += 12;
		y--;
	}

	cout << -1*(365*y + y/4 - y/100 + y/400 + 306*(m+1)/10 + d -429 - 735369) << endl;

}
