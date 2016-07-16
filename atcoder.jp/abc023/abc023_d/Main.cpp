#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> h,s;
bool check(long long c){
	vector<double> v;
	// h + sx >= c
	// x >= (c-h)/s
	for(int i=0;i<N;i++){
		v.push_back(1.*(c-h[i])/s[i]);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++){
		double x = v[i];
		if( x <= i ){
			return false;
		}
	}
	return true;
}

int main(void){
	cin >> N;
	h.resize(N);
	s.resize(N);
	for(int i=0;i<N;i++){
		cin >> h[i] >> s[i];
	}

	long long low = 0, high = 1e15, mid;
	while( low+1 < high ){
		mid = (low+high)/2;
		if( check(mid) ){
			high = mid;
		}else{
			low = mid;
		}
	}
	cout << low << endl;
	return 0;
}