#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int n,a,b;
	cin >> n >> a >> b;
	while(1){
		n-=a;
		if(n<=0){
			cout << "Ant" << endl;
			return 0;
		}
		n-=b;
		if(n<=0){
			cout << "Bug" << endl;
			return 0;
		}
	}
 
	return 0;
}