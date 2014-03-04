#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  //one, two, three, four, five, six, seven, eight, nine
  //ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen,\
nineteen
  //twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
  //hundred 7
  int a[19] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
  int b[8] = {6, 6, 5, 5, 5, 7, 6, 6};

  int sum = 0;

  for (int i = 1; i < 20; i++)
    sum += a[i - 1];
  for (int i = 20; i < 100; i++)
    {
      if (i % 10 == 0)
        sum += b[i / 10 - 2];
      else
        sum += b[i / 10 - 2] + a[i % 10 - 1];
    }
  for (int i = 100; i < 1000; i++)
    {
      //100 200 300
      if (i % 100 == 0)
        sum += a[i / 100 - 1] + 7;
      //101-119 201-219
      else if (i % 100 < 20)
        sum += a[i / 100 - 1] + 7 + 3 + a[i % 100 - 1];
      //120 130 220
      else if (i % 10 == 0)
        sum += a[i / 100 - 1] + 7 + 3 + b[i / 10 % 10 - 2];
      //121
      else
          sum += a[i / 100 - 1] + 7 + 3 + a[i % 10 - 1] + b[i / 10 % 10 - 2];
    }

  //one thousand
  sum += 11;
  cout << sum << endl;
}
