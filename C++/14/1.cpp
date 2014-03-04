#include<iostream>

using std::cout;
using std::endl;

int getTerms(int);

int main()
{
  int start = 13;
  const int limit = 1000000;
  int maxLen = 0;
  int startNum = 0;
  int temp;
  for (int i = 2; i < limit; i++)
    {
      if ((temp = getTerms(i)) > maxLen)
        {
          maxLen = temp;
          startNum = i;
        }
    }

  cout << "Max Len: " << maxLen << endl;
  cout << "Start Num: " << startNum << endl;

  return 0;
}

int getTerms(int nn)
{
  int count = 1;
  long long n = nn;
  while(1)
    {
      if (1 ==  n)
        break;
      if (n % 2 == 0)
        n /= 2;
      else
        n =  3 * n + 1;
      count++;
    }

  return count;
}