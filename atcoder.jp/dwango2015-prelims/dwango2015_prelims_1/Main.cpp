#include <bits/stdc++.h>
#define INF INT_MAX / 2
#define MOD 1000000007

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int>> PIPII;
typedef long long ll;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(void) {
	int n,x;
	cin >> n >> x;
	cout << x*540+525*(n-x) << endl;


	return 0;
}

// command shift d duplicate
// command ctrl up down
// command D
// command caps G → '' ""
// vector<vector<int>> a(N,vector<int>(M,-1));
//diff < (./a.out < input.txt) output.txt
