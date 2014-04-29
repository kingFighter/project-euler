// Math: (n, k) = (n - 1, k - 1) + (n - 1, k)
// Math: (n, k) = (n, n - k)
#include <iostream>

using namespace std;

const int UP = 100;

int v[UP + 1][UP / 2 + 1];

int main() {
  const int VALUE = 1000000;

  for (int i = 1; i <= UP; ++i)
    v[i][0] = 1;

  int count = 0;
  for (int i = 1; i <= UP; ++i) {
    for (int j = 1; j <= i / 2; ++j) {
      v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
      if (j == i / 2 && i % 2 == 0)
        v[i][j] += v[i - 1][j - 1];

      if (v[i][j] > VALUE) {
        v[i][j] = VALUE + 1;
        count += i - 2 * j + 1;
        break;
      }
    }
  }
  cout << count << endl;
  return 0;
}
