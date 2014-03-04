#include<iostream>

using std::cout;
using std::endl;

int main()
{
  const  int n = 1000;

  //multiply about 3 times that increase a digit
  const  int num = n / 3;
  int a[num] = {2};
  int size = 1;
  int carry = 0;
  int sum = 0;

  for (int i = 1; i < n; i++)
    for (int j = 0 ; j < size; j++)
      {
        a[j] = a[j] * 2 + carry;
        if (a[j] > 9)
          {
            a[j] %= 10;
            carry = 1;
            if (j + 1 == size)
              size++;
          }
        else
          carry = 0;
      }

  for(int i = size - 1; i >= 0; i--)
    {
      sum += a[i];
      cout << a[i];
    }

  cout << ": sum = " << sum << endl;

  return 0;
}
