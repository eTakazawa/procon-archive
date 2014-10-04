#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include<stack>
#include<numeric>
using namespace std;

int main(void){
	long long n;
	cin >> n;
	cout << n/2 + (n%2==0 ? 0 :3) <<endl;
	return 0;
}
