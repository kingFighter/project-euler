// 2013/6/14 by kevin
#include<iostream>
#include<cmath>

bool isPrime(int);

int main()
{
  int a = -999;
  int b = -999;
  const int LIMIT_A = 1000;
  const int LIMIT_B = 1000;
  int maxConse = 0;
  int maxPro = 0;
  int saveA, saveB;
  for (; a < LIMIT_A; a++)
    {
      for (b = -999; b < LIMIT_B; b++)
	{
	  if (!isPrime(abs(b)))//0 * 0 + a * 0 + b = b 
	      continue;
	      
	  int i = 1;
	  int count = 1;
	  while(1)
	    {
	      if (isPrime(abs(i * i  + a * i + b)))
		count++;
	      else
		break;
	      i++;
	    }

	  if (count > maxConse)
	    {
	      maxPro = a * b;
	      maxConse = count;
	      saveA = a;
	      saveB = b;
	    }
	}
    }
  std::cout << "a: " << saveA << " b: " << saveB << "\n Sum: " << maxConse << "\n Pro: " << maxPro << std::endl;

  return 0;
}

bool isPrime(int n)
{
  if (2 == n)
    return true;

  if (0 == n % 2)
    return false;
  
  int i = 3;
  int limit = static_cast<int>(sqrt(n));
  for (; i <= limit; i += 2)
    if (0 == n % i)
      return false;
  
  return true;
}
