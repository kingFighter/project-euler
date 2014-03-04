#include<iostream>
using std::cout;
using std::endl;

int main()
{
  const int n = 1000 - 1 ;
  int n1 = n / 3;
  int n2 = n / 5;
  int n3 = n / 15;
  int sum3 = n1 * (n1 + 1) / 2 * 3;
  int sum5 = n2 * (n2 + 1) / 2 * 5;
  int sum15  = n3 * (n3 + 1) / 2 * 15;
  int sum = sum3 + sum5 - sum15;
  cout << sum << endl;
  return 0;
}
