#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int query(int a,int b,int s,int t){
	if(s < a){
		if(t <= a){
			return t-s;
		}else if(t > a && t <= b){
			return a-s;
		}else if(t > b){
			return (a-s)+(t-b);
		}
	}
	else if(a <= s && s < b){
		if(t <= b){
			return 0;
		}else if(t > b){
			return t-b;
		}
	}
	else{
		return t-s;
	}
	return 0;
}
 
int main(void){
	int N,Q;
	cin >> N >> Q;
	for(int i=0;i<Q;i++){
		int a,b,s,t;
		cin >> a >>b >> s >> t;
		cout << query(a,b,s,t) * 100 <<endl;
	}
 
	return 0;
}