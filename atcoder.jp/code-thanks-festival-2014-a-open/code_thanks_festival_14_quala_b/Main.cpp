#include <iostream>
#include <string>

using namespace std;

int main(void){
	int n,a[3];
	cin >> n >> a[0] >> a[1] >> a[2];
	int sum = 0,i,k=0;
	int ret = 10000;
	for(int j=0;j<3;j++){
	sum = 0;
	for(i=0,k=0;sum<n;i++,k++){
		sum += a[(k+j)%3];
	}
	ret = min(ret,i);
}
	cout << ret <<endl;
	return 0;
}