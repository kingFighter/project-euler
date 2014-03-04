#include<iostream>
#include<cmath>

using std::cout;
using std::endl;

int getDivisor(int);

int main()
{
  long long sum = 0;
  const int limit = 9000;
  int i = 1;

  while(1)
    {
      sum += i++;

      if (getDivisor(sum) > 500)
        {
          cout << sum << endl;
          break;
        }
    }
  return 0;
}

int getDivisor(int n)
{
  int count = 0;
  int nn = static_cast<int>(sqrt(n * 1.0));

  for (int i = 1; i <= nn; i++)
    {
      if (n % i == 0)
        count += 2;
    }

  if (nn * nn == n)
    count--;

  return count;
}