#include <iostream>
using namespace std;

int main(void) {
  long long N, A, B;
  cin >> N >> A >> B;

  long long rem = N % (A + B);

  cout << A * (N / (A + B)) + min(rem, A) << endl;

  return 0;
}