#include<iostream>
#include<cmath>
using std::cout;
using std::endl;
int main()
{
  const int n = 20;
  int p[]={2,3,5,7,11,13,17,19};
  const int count = 8;
  int mul = 1;
  for (int i = 0; i < count; i++)
    mul *= pow(static_cast<double>(p[i]),static_cast<int>(log(n) / log(p[i])));

  cout << mul << endl;
  return 0;
}
