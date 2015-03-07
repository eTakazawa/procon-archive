#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,pair<int,int>> PP;
typedef long long ll;

const double EPS = 1e-8;
const int INF = 1e9;
const int MOD = 1e9+7;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

vector<ll> fact(){
	vector<ll> ret;
	ll tmp = 1;
	ret.push_back(1);
	for(int i=1;i<=10000;i++){
		tmp *= i;
		tmp %= MOD;
		ret.push_back(tmp);
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	vector<int> t(n);
	for(int i=0;i<n;i++)
		cin >> t[i];

	sort(t.begin(),t.end());
	ll sum=0,tm=0;
	for(int i=0;i<n;i++){
		sum += t[i];
		tm += sum;
	}
	cout << tm << endl;

	int cnt = 1;
	vector<int> cont;
	for(int i=1;i<n;i++){
		if(t[i] == t[i-1]){
			cnt++;
		}else{
			cont.push_back(cnt);
			cnt = 1;
		}
		if(i == n-1)cont.push_back(cnt);
	}

	long long ret = 1;
	vector<ll> vec = fact();
	for(int i=0;i<cont.size();i++){
		ret *= vec[cont[i]];
		ret %= MOD;
	}
	cout << ret << endl;
}
