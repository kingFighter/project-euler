// Brute Force

// 1+2+3+4+5+6+7+8+9 = 45    by 3 & 5
// 1+2+3+4+5+6+7+8 = 36      by 3
// 1+2+3+4+5+6+7 = 28        
// 1+2+3+4+5+6 = 21          by  3
// 1+2+3+4+5 = 15            by 3 & 5
// 1+2+3+4 = 10              by 5
// 1+2+3 = 6                 by 3
// 1+2 = 3                   by 3
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(int);
bool check(int);

int main() {
  int i = 7654321;
  for (; i >= 3; i -= 2) {
    if (isPrime(i) && check(i))
      break;
  }
  cout << i << endl;
  return 0;
}

bool isPrime(int n) {
  if (2 == n)
    return true;
  else if (0 == n % 2)
    return false;

  for (int i = 3; i <= sqrt(n); i += 2) {
    if (0 == n % i)
      return false;
  }
  return true;
}

bool check(int n) {
  int num = 0;
  int t = n;
  set<int> s;
  while (t > 0) {
    s.insert(t % 10);
    t /= 10;
    ++num;
  }
    
  if (s.size() == num && s.count(num)) {
    for (int i = num + 1; i <= 9; ++i)
      if (s.count(i))
        return false;
    return true;
  }
  else 
    return false;
}
