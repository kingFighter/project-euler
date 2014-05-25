// Level: 5
// Brute Force
// 1. Calculate the prime
// 2. Every time, we only trim the last ten digits.
#include <iostream>

using namespace std;

int main() {
  long n = 28433;
  const int COUNT = 7830457;
  for (int i = 0; i < COUNT; ++i) {
    n *= 2;
    n %= 10000000000;
  }
  cout << n + 1 << endl;
    
  return 0;
}
