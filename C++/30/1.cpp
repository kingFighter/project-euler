//by Kevin 2013/5/24
#include<iostream>
#include<cmath>

int getSpecialSum(int);

int main()
{
  const int n = 354294;
  int sum = 0;
  
  for(int i = 10; i <= n; i++)
    if(getSpecialSum(i) == i)
      sum += i;
  
  std::cout << sum << std::endl;
}

int getSpecialSum(int n)
{
  int sum = 0;

  while(n > 0)
    {
      int a = n % 10;
      n /= 10;
      sum += static_cast<int>(std::pow(a * 1.0, 5));
    }
  
  return sum;
}
