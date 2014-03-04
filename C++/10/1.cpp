#include<iostream>
#include<cmath>

using std::cout;
using std::endl;

bool isPrime(int);

int main()
{
  long long int sum = 2;
  const int num = 2000000;
  for (int i = 3; i < num; i += 2)
    if(isPrime(i))
      sum += i;

  cout << sum << endl;

  return 0;
}

bool isPrime(int n)
{
  if (n <= 1)
    return false;
  if (2 == n)
    return true;
  if (n % 2 == 0)
    return false;

  int limit = static_cast<int>(sqrt(n));
  for (int i = 3; i <= limit; i += 2)
    if (0 == n % i)
      return false;
  return true;
}

