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

int main(void) {
	int n;
	cin >> n;
	vector<int> a(n); 
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	set<int> st;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(st.find(a[i]) == st.end())cnt++;
		while(a[i]>0){
			st.insert(a[i]);
			if(a[i]%2 != 0)break;
			a[i] /= 2;
		}
	}
	cout << cnt << endl;

}