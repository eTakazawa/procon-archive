#include <bits/stdc++.h>
using namespace std;

long long data[400001],n;
long long sum(int i){
	long long s = 0;
	while(i > 0){
		s += data[i];
		i -= i & -i;
	}
	return s;
}
void add(int i, long long x){
	while(i <= n){
		data[i] += x;
		i += i & -i;
	}
}

map<int,int> zip;
int unzip[100001];
int compress(vector<int> x_){
	vector<int> x = x_;
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	for(int i=0;i<x.size();i++){
		zip[x[i]] = i;
		unzip[i] = x[i];
	}
	return x.size();
}

int main(void){
	int N;
	cin >> N;
	n = N;
	vector<int> A(N);
	vector<int> a1,a2;
	for(int i=0;i<N;i++){
		cin >> A[i];
		if(i % 2 == 0)a1.push_back(A[i]);
		else a2.push_back(A[i]);
	}

	if( N == 1 ){
		cout << 0 << endl;
		return 0;
	}else if(N == 2){
		if(A[0] > A[1])cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	compress(A);

	sort(a1.begin(),a1.end());
	sort(a2.begin(),a2.end());

	vector<int> B;
	for(int i=0;i<a1.size();i++){
		B.push_back(zip[a1[i]]);
		if(i < a2.size())B.push_back(zip[a2[i]]);
	}
		
	int cnt = 0;
	for(int i=0;i<B.size();i++){
		if(i%2==0 && B[i]%2 == 1)cnt++;
		if(i%2==1 && B[i]%2 == 0)cnt++;
	}

	long long ret = 0;
	for(int j=0;j<N;j++){
		ret += j - sum(B[j] + 1);
		add(B[j] + 1,1);
	}
	cout << cnt/2 << endl;

	return 0;
}