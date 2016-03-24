#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<double> p,w;

bool check(double x){
	priority_queue<pair<double,int>> pq;
	for(int i=0;i<p.size();i++){
		pq.push(make_pair(w[i]*(p[i]-x),i));
	}
	double salt = 0.0;
	for(int i=0;i<K;i++){
		pair<double,int> p = pq.top();pq.pop();
		salt += p.first;
	}
	if( salt >= 0.0)return true;
	else return false;
}

int main(void){
	cin >> N >> K;
	w = vector<double>(N);
	p = vector<double>(N);
	for(int i=0;i<N;i++){
		cin >> w[i] >> p[i];
		p[i] /= 100.0;
	}

	double left = 0.0,right = 100.0,mid;
	for(int i=0;i<100;i++){
		mid = (left+right)/2;
		if(check(mid)){
			left = mid;
		}else{
			right = mid;
		}
	}
	cout << fixed << setprecision(10) << left*100 << endl;
	return 0;
}