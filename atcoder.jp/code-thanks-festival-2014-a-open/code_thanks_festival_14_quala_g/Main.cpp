#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>
#include <cmath>
 
using namespace std;
#define K 203
#define double long double
#define NG 299
 
vector<double> p;
int N;
 
void sit1(int s[K],int k){
	for(int i=1;i<=k;i++){
		if(s[i]==0){
			s[i] = 1;
			break;
		}
	}
} 
void sit2(int s[K],int k){
	for(int i=1;i<=k;i++){
		if(s[i-1]==0 && s[i]==0 && s[i+1] == 0){
			s[i] = 1;
			break;
		}
	}
}
int nemba(int s[K],int k){
	for(int i=1;i<=k;i++){
		if(s[i]==0)return i;
	}
	return k+1;
}
int nembb(int s[K],int k){
	for(int i=k;i>=1;i--){
		if(s[i]==1)return i;
	}
	return 0;
}
double cntS(int s[K],int k){
	double cnt =0;
	for(int i=1;i<=k;i++){
		if(s[i]==0)cnt+=1;
	}
	return cnt;
}
 
double memo[110][300][300];
double dfs(int n,int emba,int embb,const int& k,int s[K]){
	if(n == N){
		double ans = cntS(s,k);
		//cout << ans << endl;
		return ans;
	}
	if(memo[n][emba][embb] != -1)return memo[n][emba][embb];
	
	double ret = 0;
	int ss[K];
 
	memcpy(ss,s,sizeof(ss));
	sit1(ss,k);
	ret += p[n]/100. * dfs(n+1,nemba(ss,k),nembb(ss,k),k,ss);
//cerr << nemba(ss,k) << " " << nembb(ss,k) << " ";printf(" %.15Lf\n",ret);
 
	memcpy(ss,s,sizeof(ss));
	sit2(ss,k);
	ret += (100-p[n])/100. * dfs(n+1,nemba(ss,k),nembb(ss,k),k,ss);
//cerr << nemba(ss,k) << " " << nembb(ss,k) << " ";printf(" %.15Lf\n",ret);
 
	return memo[n][emba][embb] = ret;
}
 
 
int main(void){
	int n,k;
	cin >> n >> k;
	N = n;
	k;
	p.resize(n);
	int s[K];
	memset(s,0,sizeof(s));

	for(int i=0;i<103;i++)for(int j=0;j<300;j++)for(int k=0;k<300;k++)
		memo[i][j][k] = -1;

 
	for(int i=0;i<n;i++)
		cin >> p[i];
	
	double ret = dfs(0,0,0,k,s);
 
	printf("%.10Lf\n",ret);
	return 0;
}