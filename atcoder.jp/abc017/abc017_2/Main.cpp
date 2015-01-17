#include <bits/stdc++.h>
#define INF INT_MAX / 2
#define MOD 1000000007

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int>> PIPII;
typedef long long ll;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(void) {    
    string s;
    cin >> s;
    bool f = true;
    for(int i=0;i<s.size();i++){
    	if(s[i] == 'o' || s[i] == 'k' || s[i] == 'u'){

    	}else if(i < s.size() && s[i] == 'c' && s[i+1] == 'h'){
    		i++;
    	}else{
    		f = false;
    		break;
    	}
    }
    if(f)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

// command shift d duplicate
// command ctrl up down
// command D
// command caps G → '' ""
// vector<vector<int>> a(N,vector<int>(M,-1));
//diff < (./a.out < input.txt) output.txt
