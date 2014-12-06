#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void){
	int a,b,c,m,p;
	cin >> a >> b >> c;
	p = a + b;
	m = a - b;
	if(p == c && m == c){
		cout << "?" << endl;
	}else if(p==c){
		cout << "+" << endl;
	}else if(m==c){
		cout << "-" << endl;
	}else{
		cout << "!" << endl;
	}

	return 0;
}