#include<iostream>
#include<cmath>

int getDivisorSum(int);
int getDivisorSum1(int);

int main()
{
  const  int n = 10000;

  int sum = 0;

  for (int i = 1; i < n; i++)
    {
      int other = getDivisorSum(i);
	  //We only need to find the smaller one
      if (other > i)
        if(getDivisorSum(other) == i)
          sum += other + i;
    }

  std::cout << sum << std::endl;
  return 0;
}

int getDivisorSum(int n)
{
  int sum = 0;
  int s =static_cast<int>(sqrt(n));
  for(int i = 1; i < s; i++)
    if(n % i == 0)
      sum += i + n / i;

  if( s * s == n)
    sum += n;

  return sum - n;
}

int getDivisorSum1(int n)
{
 int sum = 1;
  int p = 2;
  int j;
  int tempN = n;
  while(p * p <= n && n > 1)
    {
      if(n % p == 0)
        {
          j = p * p;
          n /= p;
          while(n % p == 0)
            {
              j *= p;
              n /= p;
			}
          sum *= (j - 1);
          sum /= (p - 1);
        }
      if(p == 2)
        p = 3;
      else
        p += 2;
    }
  // one prime factor greater than  sqrt(n) remains.
  if(n > 1)
    sum *= (n + 1);


  return sum - tempN;

}
