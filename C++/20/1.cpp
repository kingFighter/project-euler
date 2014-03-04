#include<iostream>

using std::cout;
using std::endl;

//By kevin
int main()
{
  int a[10000] = {1};
  int size = 1;
  int carry = 0;
  const int n = 100;

  for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j < size; j++)
        {
          a[j] = a[j] * i + carry;
          if (a[j] > 9)
            {
              carry = a[j] / 10;
              a[j] %= 10;
              if ( size ==  j + 1)
                size++;
            }
          else
            carry = 0;
        }
    }

  int sum = 0;
  cout << n << "! = ";
  for (int i = size - 1; i >= 0; i--)
    {
      sum += a[i];
      cout << a[i];
    }

  cout << endl;
  cout << "Sum : " << sum << endl;
  return 0;
}

