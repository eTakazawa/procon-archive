#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	vector<int> CDCases(N+1);
	for (int i = 0; i < N+1; i++) {
		CDCases[i] = i;
	}
	int now = 0;
	for (int i = 0; i < M; i++) {
		int disk;cin >> disk;
		for (int j = 1; j < N+1; j++) {
			if (CDCases[j] == disk) {
				swap(CDCases[j], now);
				break;
			}
		}
	}
	for (int i = 1; i < N+1; i++) {
		cout << CDCases[i] << endl;
	}
	return 0;
}
