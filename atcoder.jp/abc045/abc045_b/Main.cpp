#include <bits/stdc++.h>
using namespace std;

int main(void){
	vector<string> vs(3);vector<int> cnt(3);
	cin >> vs[0] >> vs[1] >> vs[2];
	int t = 0;
	for(;;){
		t = vs[t][cnt[t]++] - 'a';
		if(vs[t].size() == cnt[t]){
			cout << (char)(t + 'A') << endl;
			break;
		}
	}

	return 0;
}