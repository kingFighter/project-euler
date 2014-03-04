//by kevin 2013/5/23
#include<iostream>

int factorial(int);

int main()
{
  int n = 1000000;
  bool a[10] = {false};
  int t = 0;
  int count = 0;
  int index = 0;
  unsigned  int permutation = 0;
  int temp = 0;
  
  for (int i = 9; i >= 1; i--)
    {
      temp =  factorial(i);
      t = n / temp;
      while(count <= t)
	{
	  while(a[index++])		       
	    NULL;
	  count++;
	}
      a[index - 1] = true;

      if(permutation == 0)
	permutation = index - 1;
      else
	permutation = permutation * 10 + index - 1;
      
      n -= t * temp;
      count = 0;
      index = 0;
    }
  while(a[index++])
    NULL;
  permutation = permutation * 10 + index - 1;
  std::cout << permutation << std::endl;
}


int factorial(int n)
{
  int mul = 1;
  while(n > 1)
    mul = mul * n--;
  return mul;
}
