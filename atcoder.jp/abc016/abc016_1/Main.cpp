#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void){
	int m,d;
	cin >> m >> d;
	if(m%d ==0)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}