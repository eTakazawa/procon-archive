#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#define INF INT_MAX

using namespace std;

int bc[100][100],wc[100][100];
int main(){
	int h,w;
	cin >> h >> w;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			bc[i][j] = 0;
			wc[i][j] = 0;
		}
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if((i%2==0 && j%2==0) || (i%2==1 && j%2==1))
				cin >> bc[i][j];
			else
				cin >> wc[i][j];
		}
	}

	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++){
			bc[i][j] += bc[i][j-1];
			wc[i][j] += wc[i][j-1];
		}
	}

	for(int j=0;j<w;j++){
		for(int i=1;i<h;i++){
			bc[i][j] += bc[i-1][j];
			wc[i][j] += wc[i-1][j];
		}
	}
	int ans = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			for(int k=i;k<h;k++){
				for(int l=j;l<w;l++){
					int bsum = bc[k][l] - (i<1 ? 0 : bc[i-1][l]) - (j<1 ? 0 : bc[k][j-1]) + (i<1||j<1 ? 0 : bc[i-1][j-1]);
					int wsum = wc[k][l] - (i<1 ? 0 : wc[i-1][l]) - (j<1 ? 0 : wc[k][j-1]) + (i<1||j<1 ? 0 : wc[i-1][j-1]);
					if(bsum == wsum){
						int tmp = (k-i+1)*(l-j+1);
						//printf("(%d,%d) -> (%d,%d) = %d\n",i,j,k,l,tmp);
						ans = max(tmp,ans);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
