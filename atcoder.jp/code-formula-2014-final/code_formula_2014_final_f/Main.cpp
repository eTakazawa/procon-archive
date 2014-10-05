#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include<stack>
#include<numeric>
#include<sstream>
using namespace std;
typedef pair<int,int> P;

int main(void){

	vector<P> p;
	int x = 0,y = 1500,height = 1500;
	for(int i=100;i>0;i--){
		if(x-i*2 < 0){
			y = height-i;
			x = 1500;
			height = y-i;
		}
		x -= i;
		p.push_back(P(x,y));
		//cout << x << " " << y << endl;
		x -= i;
	}

	for(int i=99;i>=0;i--){
		cout << p[i].first << " " << p[i].second << endl;
	}


	return 0;
}
