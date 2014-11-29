#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(void){
	int n,k;
	cin >> n >> k;

	if(n >= k*2){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}