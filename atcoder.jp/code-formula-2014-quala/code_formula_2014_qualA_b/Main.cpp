#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <functional>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int main(void) {
	int a,b;
	vector<int> p,q;
	cin >> a >> b;
	for(int i=0;i<a;i++){
		int c;
		cin >> c;
		p.push_back(c);
	}
	for (int i = 0; i < b; i++) {
		int c;
		cin >> c;
		q.push_back(c);
	}

	for (int i = 7; i < 11; i++) {
		bool f = false;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == i % 10){
				cout << ". ";
			f = true;
			}
		}
		for (int j = 0; j < q.size(); j++) {
			if (q[j] == i % 10){
				cout << "o ";
			f = true;
			}
		}
		if (!f)
			cout << "x ";
	}
	cout << endl << " ";


	for (int i = 4; i < 7; i++) {
		bool f = false;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == i % 10){
				cout << ". ";
			f = true;}
		}
		for (int j = 0; j < q.size(); j++) {
			if (q[j] == i % 10){
				cout << "o ";
			f = true;}
		}
		if (!f)
			cout << "x ";
	}
	cout << endl << "  ";


	for (int i = 2; i <= 3; i++) {
		bool f = false;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == i % 10){
				cout << ". ";
			f = true;}
		}
		for (int j = 0; j < q.size(); j++) {
			if (q[j] == i % 10){
				cout << "o ";
			f = true;}
		}
		if (!f)
			cout << "x ";
	}
	cout << endl << "   ";


	for (int i = 1; i <= 1; i++) {
		bool f = false;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == i % 10){
				cout << ". ";
			f = true;}
		}
		for (int j = 0; j < q.size(); j++) {
			if (q[j] == i % 10){
				cout << "o ";
			f = true;}
		}
		if (!f)
			cout << "x ";
	}
	cout << endl;
}
