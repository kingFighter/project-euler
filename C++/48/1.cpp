#include<iostream>

int main()
{
  const int N = 1000;
  const int LEN = 10;
  long long sum = 0;
  const long long DIVISOR = 10000000000LL;
  for(int i =1; i <= N; i++)
    {
      long long temp = 1;
      for(int j = 0; j< i; j++)
	{
	  temp *= i;
	  if(temp > DIVISOR)
	    temp %= DIVISOR;
	}
      sum += temp;
      if(sum > DIVISOR)
	sum %= DIVISOR;
    }
  
  std::cout << sum << std::endl;
  return 0;
}
