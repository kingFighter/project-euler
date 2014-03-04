#include<iostream>
#include<vector>
#include<cmath>

using std::vector;

bool isPrime(int);
bool isTruncatable(int);
bool fromLeft(vector<int>&);
bool fromRight(vector<int>&);

int main()
{
  int sum = 0;
  int count = 0;
  for (int i = 11; count < 11; i += 2)
    if (isTruncatable(i))
      {
	sum += i;
	count++;
	std::cout << i << std::endl;
      }
  std::cout << "The sum of the only eleven primes that are both truncatable from left to right and right to left: "  << sum << std::endl;
  return 0;
}

bool isPrime(int n)
{
  if (n == 1)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;

  int limit = static_cast<int>(sqrt(n));
  for (int i = 3; i <= limit; i += 2)
      if (n % i == 0)
	return false;
  return true;
}

bool fromLeft(vector<int>& v)
{
  int n = 0;
  for (int i = 0, j = 1; i < v.size(); i++, j *= 10)
    {
      n = j * v[i] + n;
      if (!isPrime(n))
	return false;
    }
  return true;
}

bool fromRight(vector<int>& v)
{
  int n = 0;
  for (int i = v.size() - 1; i >= 0; i--)
    {
      n = n * 10 + v[i];
      if (!isPrime(n))
	return false;
    }
  return true;
}
bool isTruncatable(int n)
{
  vector<int> v;
  while(n != 0)
    {
      v.push_back(n % 10);
      n /= 10;
    }
  if (fromLeft(v) && fromRight(v))
    return true;
  else
    return false;
}
