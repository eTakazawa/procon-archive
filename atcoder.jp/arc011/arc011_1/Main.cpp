#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int m, n, N;
  cin >> m >> n >> N;

  int num = N, ret = N;
  while (num >= m) {
    ret += n * (num / m);
    num = (num % m) + n * (num / m);
  }
  cout << ret << endl;
  return 0;
}
