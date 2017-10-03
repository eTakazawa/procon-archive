#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int a,b,c;
  cin >> a >> b >> c;
  int cnt = 0;
  for (int i = 1; i <= 127; i++) {
    if ( i%3==a && i%5==b && i%7==c ) cout << i << endl;
  }
  return 0;
}
