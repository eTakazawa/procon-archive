#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
vector<vector<int>> A,org;
const int N = 30;

vector<int> bestlist;
void count(int y,int x,int p,vector<int>& list){
	// cout << y << " " << x << endl;
	list.push_back(x);
	list.push_back(y);
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if( p == 1 )break;
		if(ny < 0 || nx < 0 || ny >= N || nx >= N || A[ny][nx] == 0)continue;
		if( A[ny][nx] == p-1 ){		
			count(ny, nx, p-1, list);
		}
	}
	if( bestlist.size() <= list.size() ){
		bestlist = list;
	}
	list.pop_back();list.pop_back();
}

void ascSearch(int y,int x,vector<int>& list){
	list.push_back(x);
	list.push_back(y);
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= N || nx >= N || A[ny][nx] == 0)continue;
		if( A[ny][nx] > A[y][x] ){		
			ascSearch(ny, nx, list);
		}
	}
	if(bestlist.size() < list.size()){
		bestlist = list;
	}
	list.pop_back();
	list.pop_back();
}

int main(void){
	A = vector<vector<int>>(N,vector<int>(N));
	int sum = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> A[i][j];
			sum += A[i][j];
		}
	}
	org = A;
	vector<int> ans;

	int turn = 0;
	while(true){
		bestlist = vector<int>();
		bool isEnd = true;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				vector<int> list;
				if( A[i][j] == 0 )continue;
				ascSearch( i, j, list);
				isEnd = false;
			}
		}
		if(isEnd)break;

		int p = A[bestlist[1]][bestlist[0]];
		for(int i=2;i<bestlist.size();i+=2){
			int x = bestlist[i],y = bestlist[i+1];
			p++;
			for(int j=0;j<A[y][x]-p;j++){
				cout << y+1 << " " << x+1 << endl;
				ans.push_back(x);ans.push_back(y);
				A[y][x]--;
				turn++;
			}
		}
		
		p = A[bestlist[1]][bestlist[0]];
		int start = 0;
		// while(A[bestlist[start+1]][bestlist[start]] > 0){
			// cout << start << " " << bestlist.size() << endl;
			for(int i=0;i<p;i++){
				for(int j=bestlist.size()-1;j>=start;j-=2){
					int y = bestlist[j],x = bestlist[j-1];
					cout << y+1 << " " << x+1 << endl;
					ans.push_back(x);ans.push_back(y);
					A[y][x]--;
				}
				turn++;
			}
			// start += 2;
			// if(start == bestlist.size())break;
			// p = A[bestlist[start+1]][bestlist[start]];
		// }
	}
	// cerr << endl;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++){
	// 		cerr << A[i][j] << " ";
	// 	}cerr << endl;
	// }
	// cerr << endl;
	// for(int i=0;i<ans.size();i+=2){
	// 	org[ans[i+1]][ans[i]]--;
	// }
	// for(int i=0;i<30;i++){
	// 	for(int j=0;j<30;j++){
	// 		if(org[i][j] != 0)cout << org[i][j] << " ";
	// 	}
	// }cout << endl;
	cerr << "points:" << 100000 - turn << endl;
	// cerr << "greedy points:" << 100000 - sum << endl;
	return 0;
}