#include <bits/stdc++.h>
using namespace std;

int get_distance(int x1,int y1,int x2,int y2){
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main(void){
	int x1,y1,r,x2,y2,x3,y3;
	cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
	
	if( x2 <= x1-r && x1+r <= x3 && y2 <= y1-r && y1+r <= y3 ){
		cout << "NO" << endl;
		cout << "YES" << endl;
	}else if( 
		get_distance( x1, y1, x2, y2) <= r*r && 
		get_distance( x1, y1, x2, y3) <= r*r &&
		get_distance( x1, y1, x3, y2) <= r*r &&
		get_distance( x1, y1, x3, y3) <= r*r ){
		cout << "YES" << endl;
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		cout << "YES" << endl;
	}

	return 0;
}