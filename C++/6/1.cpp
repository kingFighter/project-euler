#include<iostream>
using std::cout;
using std::endl;

int main()
{
  const int n = 100;

  int sum  = (n + 1) * n >> 1;
  int sumOfSq = ((n << 1)+1) * (n + 1) * n / 6;
  int diff = sum * sum - sumOfSq;

  cout << diff << endl;
  return 0;
}
