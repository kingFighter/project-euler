// Level: 5
// Brute Force
// 1. Generate primes between 1000~9999
// 2. Check properties.
#include <iostream>
#include <set>

using namespace std;

void genPrimes(int, set<int>&);
void getNum(int, set<int>&);
int main() {
  const int N = 9999;
  const int GAP = 3330;
  set<int> s;
  
  genPrimes(9999, s);
  int n;
  for (auto i : s) {
    if (i != 1487 && s.count(i + GAP) && s.count(i + GAP * 2)) {
      set<int> t;
      getNum(i, t);
      int size = t.size();
      getNum(i + GAP, t);
      getNum(i + 2 * GAP, t);
      if (size != t.size())
        continue;
      n = i;
      break;
    }
  }
  
  cout <<  n << n + GAP << n + 2 * GAP << endl;
  return 0;
}

void genPrimes(int n, set<int> &s) {
  bool *primes = new bool[n + 1];
  fill(primes, primes + n + 1, true);
  for (int i = 2; i <= n; ++i) {
    if (primes[i]) {
      for (int j = 2; j * i <=n; ++j)
        primes[i * j] = false;
    }
  }

  for (int i = 1000; i <= n; ++i) {
    if (primes[i])
      s.insert(i);
  }
          
}

void getNum(int n, set<int>& s) {
  while (n > 0) {
    s.insert(n % 10);
    n /= 10;
  }
}
