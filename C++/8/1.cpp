#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  int max = 1;
  int a[5];
  int index = 0;
  int count = 0;
  char charN;

  //./problem < file
  // to input
  while(cin >> charN)
    {
      int n = charN - '0';
      a[index] = n;
      index = (index + 1) % 5;
      count++;
      if (count >= 5)
        {
          int temp = a[0] * a[1] * a[2] * a[3] * a[4];
          if (max < temp)
            max = temp;
        }

    }

  cout << max << endl;
  return 0;
}
