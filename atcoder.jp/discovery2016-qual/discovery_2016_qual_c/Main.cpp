#include <bits/stdc++.h>
using namespace std;

namespace sa{
const int MAX_N = 1e6;
int n,k;
int ranks[MAX_N],tmp[MAX_N];
bool compare_sa(int i,int j){
	if(ranks[i] != ranks[j])return ranks[i] < ranks[j];
	else{
		int ri = i+k<=n ? ranks[i+k] : -1;
		int rj = j+k<=n ? ranks[j+k] : -1;
		return ri < rj;
	}
}
// (ranks[i],ranks[i+k]) と (ranks[j],ranks[j+k])を比較
void construct_sa(string s,vector<int>& sa){
	sa = vector<int>(n+1);
	for(int i=0;i<=n;i++){
		sa[i] = i;	// ソートする前のsuffix array
		ranks[i] = i < n ? s[i] : -1; // 文字コードを入れる
	}

	for(k = 1;k <= n;k *= 2){
		sort( sa.begin(), sa.end(), compare_sa);
		tmp[sa[0]] = 0;
		for(int i=1;i<=n;i++){ // 同じ値ならranksをincrease更新しない
			tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
		}
		for(int i=0;i<=n;i++){ // ranksを更新
			ranks[i] = tmp[i];
		}
	}
}
}

int main(void){
	string s;
	int k;
	cin >> s >> k;
	int count_a = 0, start = 0, left = k, count = 0;
	for(int i=0;i<s.size();i++){
		if( s[i] == 'a' ){
			if( i-count_a <= k ){
				start = i+1;
				left = k - (i-count_a);
				count = i + 1;
			}
			count_a++;
		}
	}

	if( count_a + k >= s.size() ){
		for(int i=0;i<s.size()-k;i++)cout << "a";
			cout << endl;
		return 0;
	}

	vector<int> sa;
	sa::n = s.size();
	sa::construct_sa(s,sa);

	string min_s;
	for(int i=0;i<sa.size()-1;i++){
		if(start <= sa[i] && sa[i] <= start+left){
			min_s = s.substr(sa[i]);
			break;
		}
	}

	for(int i=0;i<count+left;i++)cout << "a";
	cout << min_s << endl;


	return 0;
}
