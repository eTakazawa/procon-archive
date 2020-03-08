#include <iostream>
#include <list>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  list<char> ret;
  for (const auto& c : s) {
    ret.push_back(c);
  }

  int Q, rev = 0;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int t;
    cin >> t;
    if (t == 1) {
      // reverse
      rev = rev ? 0 : 1;
    }
    else if (t == 2) {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        // add front c
        if (rev) ret.push_back(c);
        else ret.push_front(c);
      }
      else {
        // add back c
        if (rev) ret.push_front(c);
        else ret.push_back(c);
      }
    }
  }

  string out;
  for (const auto& c : ret) {
    out += c;
  }
  if (rev) reverse(out.begin(), out.end());
  cout << out << endl;

  return 0;
}