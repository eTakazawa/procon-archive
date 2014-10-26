#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include<utility>
using namespace std;

int main(void){
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	vector<int>al1(26),al2(26),al3(26),co(26);
	for(int i=0;i<s1.size();i++){
		al1[s1[i]-'A']++;
		al2[s2[i]-'A']++;
		al3[s3[i]-'A']++;
	}
	co = al1;

	int used = 0;
	for(int i=0;i<26;i++){
		if(al3[i]>0){
			int tmp = min(al3[i],al1[i]);
			al3[i] -= tmp;
			al1[i] -= tmp;
			used += tmp;
		}
	}

	for(int i=0;i<26;i++){
		if(al3[i]>0){
			int tmp = min(al2[i],al3[i]);
			al3[i] -= tmp;
			al2[i] -= tmp;
		}
		if(used>s3.size()/2 && al2[i] > 0){
			int tmp = min(co[i]-al1[i],al2[i]);
			tmp = min( used - (int)s3.size()/2,tmp);
			al2[i] -= tmp;
			used -= tmp;
		}
	}

	if(used != s3.size()/2){
		cout << "NO" <<endl;
		return 0;
	}
	for(int i=0;i<26;i++){
		if(al3[i] > 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" <<endl;
	return 0;
}
