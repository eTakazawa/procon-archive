#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cctype>
#include<vector>
#include<cstring>
#define INF 99999999

using namespace std;

int vx[4]={-1,0,1,0};
int vy[4]={0,1,0,-1};

int main(){
	map<string,int>dic;
	vector<string> s;
	int n;
	cin >> n;

	for(int i=0;i<n;i++){
		string b;cin >> b;
		dic[b]=0;
		s.push_back(b);
	}

	for(int i=0;i<n;i++){
		dic[s[i]]++;
	}

	int ans=0;
	string ret;
	map<string,int>::iterator it=dic.begin();
	while(it!=dic.end()){
		if(ans<it->second){
			ans=it->second;
			ret = it->first;
		}
		it++;
	}
	cout << ret << endl;
}