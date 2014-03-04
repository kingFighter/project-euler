// 2013/6/9 by Kevin
#include<iostream>

int a[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int get_factorial_sum(int);

int main()
{
  const int up_limit = 2540160;
  int sum = 0;

  for (int i = 10; i <= up_limit; i++)
    if (get_factorial_sum(i) == i)
      sum += i;

  std::cout << sum << std::endl;
  return 0;
}

int get_factorial_sum(int n)
{
  int sum = 0;
  while (n != 0)
    {
      sum += a[(n % 10)];
      n /= 10;
    }
  
  return sum;
}
