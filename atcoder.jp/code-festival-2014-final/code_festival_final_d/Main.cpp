#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	long long A;
	cin >> A;

	if(A==1)cout << 1 << " " << 1 << endl;
	else cout << A+1 << " " << 2 << endl;

	return 0;
}

/*const int max_n = 5000;
long long ** C = new long long*[max_n + 1];
for (int i = 0; i <= max_n; i++) {
	C[i] = new long long[i + 1];
	for (int j = 0; j <= i; j++){
		if ((j == 0) || (j == i)) {
			C[i][j] = 1;
		} else {     //            Pascal's rule
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

		}
		if(C[i][j] == A){
			cout << i+1 << " " << j+1 <<endl;
			return 0;
		}
	}
}
cout << -1 << endl;*/