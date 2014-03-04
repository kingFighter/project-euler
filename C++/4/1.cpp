#include<iostream>
#include<cmath>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
bool palindromic(int n);
int main()
{
  int n1 = 999;
  int n2;
  int nn1,nn2;
  while(n1 > 99)
    {
      n2 = n1;
      while(n2-- > 99)
        if(palindromic(n1 * n2))
          {
            if(n1 * n2 > nn1 * nn2)
              {
                nn1 = n1;
                nn2 = n2;
              }
          }
      n1--;
    }
  cout << nn1 * nn2 << " = " << nn1 << "*" << nn2 <<endl;
  return 0;
}
bool palindromic(int n)
{
  vector<int> v;
  while(n > 0)
    {
      v.push_back(n % 10);
      n /= 10;
    }
  for(int i = 0; i < v.size() / 2; i++)
    if(v[i] != v[v.size() - 1 - i])
      return false;

  return true;
}