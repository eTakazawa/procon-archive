//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <utility>
#define INF INT_MAX / 2
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

bool is_prime(int n){
	if(n == 1)return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}

int main(void) {
	int n;
	cin >> n;
	int sum = (1+n)*n/2;
	if(is_prime(sum))cout << "WANWAN" << endl;
	else cout << "BOWWOW" << endl;

}

// command shift d duplicate
// command ctrl 上下
// command D
// command caps G → '' ""
// vector<vector<int>> a(N,vector<int>(M,-1));