#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define inf 10000000

int main() {
	int N;
	cin >> N;
	vector<int>R(N),L;
	for(int i=0;i<N;i++)
		cin >> R[i];

	int cnt = 0;
	int la,lb;
	int lc = 0;
	la = lb = R[0];

	for(int i=1;i<N;i++){
		if(la > R[i] && (lc==1 || lc==0)){
			lc = -1;
			lb = R[i];
			cnt++;
		}else if(lb < R[i] && (lc==-1 || lc==0)){
			lc = 1;
			la = R[i];
			cnt++;
		}else if(R[i] == la || R[i] == lb){
			continue;
		}else if(lc == 1){
			la = max(la,R[i]);
		}else if(lc == -1){
			lb = min(lb,R[i]);
		}
	}


	if(N<3 || cnt==1 || cnt==0)cout << 0 << endl;
	else cout <<cnt+1 << endl;

	return 0;
}
