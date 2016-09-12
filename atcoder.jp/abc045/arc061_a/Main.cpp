#include <bits/stdc++.h>
using namespace std;

long long ret;
void func(string s,int n,vector<int>& l){
	if(n == s.size()){
		if(l.size() == 0){
			ret += stoll(s);
		}else{
			long long tmp = 0;
			cerr << s.substr( 0, l[0]) << " ";
			tmp += stoll(s.substr( 0, l[0]));
			for(int i=1;i<l.size();i++){
				cerr << s.substr( l[i-1], l[i]-l[i-1]) << " ";
				tmp += stoll(s.substr( l[i-1], l[i]-l[i-1]));
			}
			cerr << s.substr(l[l.size()-1]) << " ";
			tmp += stoll(s.substr(l[l.size()-1]));
			cerr << endl;
			ret += tmp;
		}
		return;
	}

	func(s,n+1,l);
	l.push_back(n);
	func(s,n+1,l);
	l.pop_back();
}

int main(void){
	string s;
	cin >> s;
	vector<int> l;
	func(s,1,l);
	cout << ret << endl;
	return 0;
}