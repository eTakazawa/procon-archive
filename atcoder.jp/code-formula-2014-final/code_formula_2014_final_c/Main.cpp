#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include<stack>
#include<numeric>
using namespace std;

int main(void){
	string s,tmp;
	map<string,int>m;

	getline(cin,s);
	bool f=false;
	for (int i = 0; i < s.size(); i++) {
		if(s[i]=='@' && s[i+1]!='@' && s[i+1]!=' '){
			i++;
			while(s[i]!='@' && s[i]!=' ' && i<s.size()){

				tmp += s[i];
				i++;
			}
			i--;
			if(tmp!="")
				m[tmp]=1;
			tmp = "";
		}
	}

	map<string,int>::iterator it = m.begin();
	while(it!=m.end()){
		cout << (*it).first << endl;
		it++;
	}


	return 0;
}
