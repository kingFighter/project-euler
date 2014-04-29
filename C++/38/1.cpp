// Brute Force
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
  // n initial value: 4 digit
  // 2 * n 5 digit
  // if n is larger than 4 digit, then 2 * n will larger than 5 digit
  // Then we get largest n:9876

  // And we know staring with 9, we can get 918273645, so the lest
  // most digit of n must be 9, Then we get smallest n:9123

  int n = 9876, t;
  int max = 0;
  
  for (; n >= 9123; --n) {
    string all, tmp;
    for (int i = 1; ; ++i) {
      t = n * i;
      all += to_string(t);
      tmp += to_string(t);
      if (all.size() > 9)
        break;

      sort(all.begin(), all.end());
      int j = 0;
      for (; all.size() == 9 && j < 9; ++j) {
        if (all[j] != '0' + j + 1)
          break;
      }
      if (j == 9) {
        int t = atoi(tmp.c_str());
        if (t > max)
          max = t;
      }
    }
  }
  cout << max << endl;
  return 0;
}
