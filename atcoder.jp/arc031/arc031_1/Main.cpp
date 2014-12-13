#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

int main(void){
	string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] != s[s.size()-1-i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" <<endl;
    

    return 0;
}
