// Level: 2
// 1. generate primes by Sieve of Eratosthenes
// 2. calculate consecutive prime sum starting from 2
// 3. set the longest span from 0 to primes.size()
// 4. minus primeSums which span across numOfPrime to prime.size()
// 5. if the result is less than UP, and is a prime, set the new
// numOfPrime
// 6. continue 3 to the end
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void generatePrime( int, vector<int>&);

int main() {
  const int UP = 1000000;
  vector<int> primes;
  generatePrime(UP, primes);
  int numOfPrime = 0;
  vector<int> primeSum;
  int result;
  primeSum.push_back(0);
  for (int i = 0; i < primes.size(); ++i) {
    primeSum.push_back(primeSum[i] + primes[i]);
  }
    
  for (int i = numOfPrime; i <= primes.size(); ++i) {
    for (int j = i - numOfPrime + 1; j >= 0; --j) {
      int gap = primeSum[i] - primeSum[j];
      if (gap > UP) 
        break;

      if (binary_search(primes.begin(), primes.end(), gap)) {
        numOfPrime = i - j;
        result = primeSum[i] - primeSum[j];
      }
    }
  }
  cout << numOfPrime << " " << result << endl;
}

void generatePrime(int n, vector<int> &primes) {
  bool *prime = new bool[n + 1];
  fill(prime, prime + n + 1 , true);
  for (int i = 2; i <= sqrt(n); ++i) {
    if (prime[i]) {
      for (int j = 2; j * i <= n; ++j)
        prime[i * j] = false;
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (prime[i])
      primes.push_back(i);
  }
}
