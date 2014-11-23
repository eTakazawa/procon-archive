#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<cstdio>

using namespace std;

int main(void){
    string a,b;
    cin >> a >> b;
    cout << (a.size() > b.size() ? a : b) << endl;
    return 0;
}
