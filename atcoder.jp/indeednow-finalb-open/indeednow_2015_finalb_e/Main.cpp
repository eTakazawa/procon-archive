#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
const int INF = 1e9;

template <class T>
struct BIT{
    int N;vector<T>bit;
    BIT(int n):N(n),bit(n+1){}
    void add(T k,int i){i++;for(int x=i;x<=N;x+=x&-x)bit[x]+=k;}
    T sum(int i){i++;T r=0;for(int x=i;x>0;x-=x&-x)r+=bit[x];return r;}
    T sum(int l,int r){return l<=r ? sum(r)-sum(l-1):sum(r)+sum(l,N-1);}
    T get(int i){return sum(i) - sum(i-1);}
    void set(T k,int i){add(k-get(i),i);}
};

//座標圧縮
int compress(vector<int>& X){
	vector<int> x = X;
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	for(int i=0;i<X.size();i++){
		X[i] = lower_bound(x.begin(),x.end(),X[i]) - x.begin();
	}
	return x.size();
}

int main(void) {
	int n;
	cin >> n;
	vector<int> h(n),H;
	vector<int> id(n);

	for(int i=0;i<n;i++){
		cin >> h[i];
	}
	H = h;

	if(n != compress(h)){
		cout << -1 << endl;
		return 0;
	}

	BIT<int> bit(n+1);
	for(int i=0;i<n;i++){
		bit.set(1,i);
		id[h[i]] = i;
	}

	ll ans = 0;
	for(int i=0;i<n;i++){
		//cout << bit.sum(0,id[i]) << endl;
		ans += (ll)(bit.sum(0,id[i])-1) * H[id[i]];
		bit.add(-1,id[i]);
		//cout << ans << endl;
	}

	cout << ans << endl;
	return 0;
}