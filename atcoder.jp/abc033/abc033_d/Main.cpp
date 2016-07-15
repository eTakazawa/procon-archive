#include <bits/stdc++.h>
using namespace std;

static const double EPS = 1e-10;

int vcnt,cnt;
void func(vector<long double>& degs){
	int n = degs.size();
	vcnt = cnt = 0;
	for(int i=0;i<n;i++){
		degs.push_back(degs[i] + M_PI*2);
	}

	int s = 0, t = 0;
	for(int i=0;i<n;i++){
		while( degs[s] - degs[i] < M_PI / 2 - EPS)s++;
		while( degs[t] - degs[i] < M_PI + EPS)t++;
		if( fabs(degs[i] + M_PI / 2 - degs[s]) < 2*EPS){
			vcnt++;
			s++;
		}
		cnt += t - s;
	}
}

int main(void){
	int N;
	cin >> N;
	vector<long double> x(N),y(N);
	for(int i=0;i<N;i++){
		cin >> x[i] >> y[i];
	}

	long long tyoku = 0,donkaku = 0;
	for(int i=0;i<N;i++){
		vector<long double> degs;
		for(int j=0;j<N;j++){
			if( i == j )continue;
			degs.push_back( atan2( (y[j]-y[i]), (x[j]-x[i]) ) );
		}
		sort(degs.begin(),degs.end());
		func(degs);
		tyoku += vcnt;
		donkaku += cnt;
	}
	cout << (long long)N*(N-1)*(N-2)/6-tyoku-donkaku << " " << tyoku << " " << donkaku << endl;
	return 0;
}