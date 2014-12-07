#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;
	vector<int> p(n),s(m);
	for(int i=0;i<n;i++)
		cin >> p[i];
	for(int i=0;i<m;i++){
		cin >> s[i];
		s[i]--;
	}

	int sum = 0;
	for(int i=0;i<m;i++){
		sum += p[s[i]];
	}
	cout << sum <<endl;
	return 0;
}