#include<iostream>
#include<cmath>

using std::cout;
using std::endl;

int main()
{
  const int s = 1000;
  for(int i = 3; i < (s - 3) / 3; i++)
    for (int j = i; j < (s - 1 - i) / 2; j++)
      {
        if (i * i + j * j == (1000 - i - j) * (1000 - i - j))
          {
            cout << i * j * (1000 - i -j) << " = " << i << " " << j << " " << (1000 - i - \
j) << endl;
            return 0;
          }
      }
  return 0;
}


