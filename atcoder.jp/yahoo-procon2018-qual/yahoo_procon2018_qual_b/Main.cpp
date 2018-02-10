#include <bits/stdc++.h>
using namespace std;
int main(void) {
int X, K;
cin >> X >> K;

int a = pow(10, K);
for (int i = 0;; i+=a) {
if ( i > X ) {
cout << i << endl;
break;
}
}

return 0;
}