#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N,M;
	cin >> N >> M;
	int X,Y;
	cin >> X >> Y;
	vector<int> a(N),b(M);
	for(int i=0;i<N;i++)
		cin >> a[i];
	for(int i=0;i<M;i++)
		cin >> b[i];


	int now = 0, pos = 0,cnt = 0;
	for(;;){
		if(pos == 0){
			auto it = lower_bound(a.begin(),a.end(),now);
			if(it == a.end())break;
			now = *it + X;
			pos = 1;
		}else{
			auto it = lower_bound(b.begin(),b.end(),now);
			if(it == b.end())break;
			now = *it + Y;
			pos = 0;
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}