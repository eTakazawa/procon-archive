#include <bits/stdc++.h>
using namespace std;

double win_prob(double rp, double rq){
	return 1.0/(1.0+pow(10,(rq-rp)/400));
}

int main(void){
	int k;
	cin >> k;
	vector<double> r(1<<k);
	for(int i=0;i<(1<<k);i++){
		cin >> r[i];
	}

	// cerr << win_prob(2200, 2600) * (
	// 					win_prob(2000, 1800) * win_prob(2200, 2000) +
	// 					win_prob(1800, 2000) * win_prob(2200, 1800))  << endl;

	vector<double> prob(1 << k, 1.0);
	for (int d = 1; d <= k; d++) {
		vector<double> next_prob(prob);
		for (int s = 0; s < (1 << k); s += (1 << d)) {
			for (int i = s; i < s + (1 << d); i++) {
				double sum = 0.0;
				for (int w = 0; w < (1 << d); w++) {
					int j = s + w;
					if (j == i) continue;
					if (i / (1 << d-1) == j / (1 << d-1)) continue;
					// cerr << i << " vs. " << j << endl;
					sum += prob[j] * win_prob(r[i], r[j]);
				}
				// cerr << prob[i] * sum << endl;
				next_prob[i] = prob[i] * sum;
			}
		}
		swap(prob, next_prob);
	}
	for (int i = 0; i < (1 << k); i++) {
		cout << fixed << setprecision(10) << prob[i] << endl;
	}

	return 0;
}