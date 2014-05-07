// Level: 5
// Brute Force
// 1. Generate Primes under 100000
// 2. Loop from 2 * 3 * 5 * 7, and check the number of primes
// 3. Find the first four consecutive integers 
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void genPrime(int, vector<int> &);
void getPrimeNum(int, set<int> &);

vector<int> v;

int main() {
  genPrime(100000, v);  
  int  i = 2 * 3 * 5 *7;
  const int N = 4;
  set<int> s;
  int count = 0;
  while (count < N) {
    s.clear();
    getPrimeNum(i, s);
    if (s.size() == N)
      ++count;
    else
      count = 0;

    ++i;
    
  }
  cout << i - N << endl;
  return 0;
}

void genPrime(int n, vector<int> &v) {
  bool *primes = new bool[n + 1];
  fill(primes, primes + n + 1, true);
  for (int i = 2; i <= n; ++i) {
    if (primes[i]) {
      for (int j = 2; j * i <= n; ++j) 
        primes[i * j] = false;
    }
  }
  
  for (int i = 2; i <= n; ++i) {
    if (primes[i])
      v.push_back(i);
  } 

  delete [] primes;
}

void getPrimeNum(int n, set<int> &s) {
  for (auto it = v.begin(); it != v.end() && n != 1; ++it) {
    while (n % *it == 0) {
      s.insert(*it);
      n /= *it;
    }
  }
}
