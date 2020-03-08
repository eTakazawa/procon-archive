#include <iostream>
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;

  for (int i = 0; i < 1000000; i++) {
    int eight = int(i * 0.08);
    int ten = int(i * 0.1);
    if (eight == A && ten == B) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}