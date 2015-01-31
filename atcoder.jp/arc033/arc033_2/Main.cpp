#include <bits/stdc++.h>
#define INF INT_MAX / 2
#define MOD 1000000007

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int>> PIPII;
typedef long long ll;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(void) {
	int na,nb;
	cin >> na >> nb;
	vector<int> a(na),b(nb);
	set<int> s;
	for(int i=0;i<na;i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	int cnt = 0;
	for(int i=0;i<nb;i++){
		cin >> b[i];
		if( s.find(b[i]) != s.end())cnt++;
	}

	for(int i=0;i<nb;i++){
		s.insert(b[i]);
	}

	printf("%.10f\n",(double)cnt/s.size());


	return 0;
}