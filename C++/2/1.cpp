#include<iostream>
using std::cout;
using std::endl;

int main()
{
  int n1 = 2;
  int n2 = 8;
  int sum = n1;
  while( n2 < 4000000)
    {
      sum += n2;
      n2 = (n2 << 2) + n1;
      n1 = (n2 - n1) >> 2;
    }
  cout << sum << endl;
}


