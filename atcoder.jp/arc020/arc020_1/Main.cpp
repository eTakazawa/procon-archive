#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	if(abs(a-0)>abs(b-0))cout << "Bug" << endl;
	else if(abs(a-0)<abs(b-0))cout << "Ant" << endl;
	else cout << "Draw" << endl;
	return 0;
}