// Brute Force
#include <iostream>

using namespace std;

int test(int n) {
  int count = 0;
  for (int i = 1; i <= n / 3; i++) {
    for (int j = i; j <= n / 2; j++)  {
      int k = n - i - j;
      if (i * i + j * j == k * k)
        count++;
    }
  }
  return count;
}

int main() {
  int p = 3;
  int count = 0;
  int v = p;
  for (; p <= 1000; p++) {
    int t = test(p);
    if (count < t) {
      count = t;
      v = p;
    }
  }
  cout << v << endl;
  return 0;
}
