// 10^(n-1) <= x^n < 10^n
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n = 1;
  int low = 0;
  int count = 0;
  while (low < 10) {
    low = ceil(pow(10, (n - 1.0) / n));
    count += 10 - low;
    ++n;
  }
  cout << count << endl;
  return 0;
}
