#include <bits/stdc++.h>

using namespace std;

long double mat[1010][1010];
void pascal_tri(){
	const int N = 1005;
	mat[0][0] = 1.0;
	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			if(j == 0)mat[i][j] = mat[i-1][j] / 2.0;
			if(j == i)mat[i][j] = mat[i-1][j-1] / 2.0;
			else mat[i][j] = (mat[i-1][j-1] + mat[i-1][j]) / 2.0;
		}
	}
}

int main(void){
	int N,D;
	int X,Y;
	cin >> N >> D >> X >> Y;
	if(X%D != 0 || Y%D != 0 ){
		cout << 0 << endl;
		return 0;
	}
	pascal_tri();
	X /= D;
	Y /= D;
	D = 1;
	X = abs(X);
	Y = abs(Y);
	long double ret = 0.0;
	for(long long i=0;i<=N;i++){
		if(!(i>=X&&N-i>=Y))continue;
		if(!((i-X)%2==0&&(N-i-Y)%2==0))continue;
		long double tmp = mat[N][i]*mat[i][(i+X)/2]*mat[N-i][(N-i+Y)/2];
		// cout << N << " " << i+X << " " << (N-i)+Y << endl;
		// cout << tmp << endl;
		ret += tmp;
	}

	cout << fixed << setprecision(15) << ret << endl;
	return 0;
}
