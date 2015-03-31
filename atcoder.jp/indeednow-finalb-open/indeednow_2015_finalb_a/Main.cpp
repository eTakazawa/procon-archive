#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
const int INF = 1e9;

int main(void) {
	int A,B;
	cin >> A >> B;
	vector<ll> a(1000001);
	for(ll i=0;i<1000001;i++){
		a[i] = i*i*(i+1)/2;
	}
	ll ans = 0;
	for(int i=A;i<=B;i++){
		ans += a[i];
		ans %= (ll)1e9+7;
	}
	cout << ans << endl;
	return 0;
}