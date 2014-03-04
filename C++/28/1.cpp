#include<iostream>

void method1();

const int n = 1001;

int main()
{
  unsigned int sum = 1;
  int  i = 2;
  int interval = 0;
  int num = 1;

  while(i <= n)
    {
      num += i;
      sum += num;

      interval++;
      if(interval == 4)
	{
	  interval = 0;
	  i += 2;
	}

    }
  
  std::cout << sum << std::endl;
  method1();

  return 0;
}

void method1()
{
  int i = 3;
  int sum = 1;
  while(i <= n)
    {
      sum += 4 * i * i - 6 * (i - 1);
      i += 2;
    }
  std::cout << sum << std::endl;
}

