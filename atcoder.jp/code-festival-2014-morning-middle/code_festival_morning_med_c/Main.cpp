#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include<algorithm>
#include <utility>
#include <climits>
using namespace std;

double p[128][2];
int main() {
	long long n;
	cin >> p[0][1] >> n;
	p[0][0] = 1.0 - p[0][1];

	for(int i=1;i<200;i++){
		p[i][1] = 2 * p[i-1][0] * p[i-1][1];
		p[i][0] = 1.0 - p[i][1];
	}
	double status[2];
	status[0] = 0;status[1]=1;
	for(int i=0;i<63;i++){
		if(n & (1LL << i)){
			double tmp0,tmp1;
			tmp0 = status[0]  * p[i][0] +status[1] * p[i][1];
			tmp1 = status[1] * p[i][0] + status[0] * p[i][1];
			status[0] = tmp0;
			status[1] = tmp1;
		}
	}
	printf("%.10f\n",status[0]);
	return 0;
}
