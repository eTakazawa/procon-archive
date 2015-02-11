#include <bits/stdc++.h>
#define INF INT_MAX / 2
#define MOD 1000000007

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int>> PIPII;
typedef long long ll;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(void){
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i=0;i<n;i++)
		cin >> h[i];

	stack<int> st;

	for(int i=0;i<n;i++){
		cout << st.size() << endl;
		while(!st.empty() && st.top() < h[i]){
			st.pop();
		}
		st.push(h[i]);
	}


	return 0;
}