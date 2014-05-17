// Level: 5
// Brute Force
// n = (sqrt(24 * p + 1) + 1)/ 6, check if n is integer.
#include <iostream>
#include <set>
#include <cmath>

using namespace std; 

bool isPen(int);

int main() {
  int i = 1;
  bool find = false;
  int d = 0;
  while (!find) {
    ++i;
    int n = i * (3 * i - 1) / 2;
    for (int j = i - 1; j > 0; --j) {
      int m = j * (3 * j - 1) / 2;
      if (isPen(n + m) && isPen(n - m)) {
        find = true;
        d = n - m;
        break;
      }
    }
  }
  cout << d << endl;;
  return 0;
}

bool isPen(int n) {
  double m = (sqrt(1 + 24 * n) + 1) / 6;
  return m == static_cast<int>(m);
}
