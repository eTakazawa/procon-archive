#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,M;
	cin >> N >> M;

	vector<int> x(N);
	vector<int> nums(200001);
	vector<int> cnt(100001);
	for(int i=0;i<N;i++){
		cin >> x[i];
		nums[ abs( x[i] - ceil(1. * x[i] / M) * M ) ]++;
		cnt[x[i]]++;
	}

	vector<int> kumi(200001);
	for(int i=0;i<100001;i++){
		if( cnt[i] >= 2 ){
			kumi[ abs( i - ceil( 1. * i / M ) * M ) ] += cnt[i] / 2 * 2;
		}
	}

	// if( M == 1 ){
	// 	cout << N/2 << endl;
	// 	return 0;
	// }

	int ret = 0;
	for(int i=0;i<M;i++){
		if(nums[i]){
			// cout << i << " " << nums[i] << endl;
			if(i != 0 && i != M-i){
				int mx = min(nums[i],nums[M-i]);
				nums[i] -= mx;
				nums[M-i] -= mx;
				ret += mx;

				int same = min( kumi[i] , nums[i] ) / 2;
				cerr << i << " " << same << endl;
				ret += same;
				nums[i] -= same * 2;
			}else{
				int same = nums[i] / 2;
				ret += same;
				nums[i] -= same * 2;
			}
		}
	}
	cout << ret << endl;
	return 0;
}