// 2013/6/14 by kevin
#include<iostream>
#include<cmath>

bool isPrime(int);
bool isCircularPrime(int);

int main()
{
  int sum = 13;//below 100 there're 13
  const int UP_LIMIT = 1000000;

  int i = 101;
  for (; i < UP_LIMIT; i += 2)
    if (isCircularPrime(i))
      sum++;
  
  std::cout << sum << std::endl;

  return 0;
}

bool isPrime(int n)
{
  if (0 == n % 2)
    return false;

  int i = 3;
  int upLimit = static_cast<int>(sqrt(n));
  for (;i <= upLimit; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

bool isCircularPrime(int n)
{
  int  count = 0;
  int nn = n;
  while(nn != 0)
    {
      nn /= 10;
      count++;
    }
  
  int i;
  int remainder;
  for(i = 0; i < count; i++)
    {
      if (!isPrime(n))
	return false;
      
      remainder = n % 10;
      n /= 10;
      n = n + remainder * static_cast<int>(pow(10, count - 1));
    }

  return true;
}
