#include<iostream>
#include<cmath>

using std::cout;
using std::endl;
using std::cin;

bool isPrime(int);

int main()
{
  int count = 1;
  int i = 3;
  int target = 2;
  int index;
  cin >> index;
  for(; count < index; i += 2)
    {
      if (isPrime(i))
        {
          count++;
          target = i;
        }
    }

  cout << target << endl;

  return 0;
}

bool isPrime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}