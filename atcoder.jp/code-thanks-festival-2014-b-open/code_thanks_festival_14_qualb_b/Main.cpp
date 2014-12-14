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
#include <queue>
#define ll long long

using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >>c;

    cout << max(a*b*c,max((a+b)*c,max(a+b+c,a*b+c))) << endl;

    return 0;
}
