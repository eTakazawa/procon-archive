#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int v[55][55];

void set(int ra,int rb,int ca,int cb){
	v[ra][ca]++;
	v[rb][ca]--;
	v[ra][cb]--;
	v[rb][cb]++;
}

int imos(int R,int C){
	for(int r=0;r<R;r++){
		for(int c=1;c<C;c++){
			v[r][c] += v[r][c-1];
		}
	}
	for(int r=1;r<R;r++){
		for(int c=0;c<C;c++){
			v[r][c] += v[r-1][c];
		}
	}
	int ret = 0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			//cerr << v[i][j] << " ";
			if( v[i][j]%4 == 0 )ret++;
		}
		//cerr << endl;
	}
	//cerr << endl;
	return ret;
}

int main(void){
	int R,C,M,N;
	cin >> R >> C >> M;
	cin >> N;

	vector<int> ra,rb,ca,cb;
	for(int i=0;i<N;i++){
		int r1,r2,c1,c2;
		cin >> r1 >> r2 >> c1 >> c2;
		r1--;c1--;
		ra.push_back(r1);
		rb.push_back(r2);
		ca.push_back(c1);
		cb.push_back(c2);
	}

	for(int i=0;i<N;i++){
		memset(v,0,sizeof(v));
		for(int j=0;j<N;j++){
			if(i==j)continue;
			set(ra[j],rb[j],ca[j],cb[j]);
		}
		int ret= imos(R,C);
		if(ret == M)cout << i+1 << endl;
	}




	return 0;
}