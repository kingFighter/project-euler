#include<iostream>

using std::cout;
using std::endl;

//2013/4/27 by Kevin
//brute force
//nothing peculiar to say
int main()
{
  int a[1000]={1},b[1000]={1};
  int count = 2;
  int size = 1;

  while(b[999] <= 0)
    {
      int c[1000]={0};
      for(int  i = 0; i < size; i++)
        {
          c[i] = c[i] + a[i] + b[i];
          if (c[i] > 9)
            {
              if (i + 1 == size)
                size++;
              c[i + 1] = c[i] / 10;
              c[i] %= 10;
            }
        }
      for (int i = 0; i < size; i++)
        {
          a[i] = b[i];
          b[i] = c[i];
        }
      count++;
    }

  cout << "The num:\n";
  for (int i = size - 1; i >= 0; i--)
    cout << b[i];
  cout << endl;
  cout << "The " << count << " term.\n";
  return 0;
}



