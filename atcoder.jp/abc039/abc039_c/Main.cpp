#include <bits/stdc++.h>
using namespace std;

int main(void){
	string piano = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
	vector<string> onkai = {"Do","Re","Mi","Fa","So","La","Si"};

	vector<int> po(piano.size(),-1);
	int cnt = 0;
	for(int i=0;i<piano.size();i++){
		if(piano[i] == 'W'){
			po[i] = cnt % onkai.size();
			cnt++;
		}
	}
	string s;
	cin >> s;
	int id = piano.find(s);
	// cout << id << endl;
	cout << onkai[po[id]] << endl;

	return 0;
}