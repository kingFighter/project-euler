// Level: 5
// Brute Force
// 1. Composite number is odd then prime is larger than 2
// 2. We will generate primes between [3, n]
// 3. We check if (n - prime) / 2 is square
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isOK(int);
void genPrime(int, vector<int> &); // not include 2

int main() {
  int  n = 33;
  while (isOK(n)) {
    n += 2;
  }
  cout << n << endl;
    return 0;
}


bool isOK(int n) {
  vector<int> v;
  genPrime(n, v);
  int t, tt;
  for (auto i : v) {
    t = (n - i) / 2;
    tt = sqrt(t);
    if (tt * tt == t)
      return true;
  }
  return false;
}

void genPrime(int n, vector<int> &primes) {
  bool *prime = new bool[n + 1];
  fill(prime, prime + n + 1, true);
  for (int i = 2; i <= sqrt(n); ++i) {
    if (prime[i]) {
      for (int j = 2; i * j <= n; ++j) {
        prime[i * j] = false;
      }
    }
  }

  for (int i = 3; i <= n; ++i) {
    if (prime[i])
      primes.push_back(i);
  }
}
