#include <iostream>
#include <vector>

using namespace std;

unsigned int getLen(unsigned int);

// For debug
void display(vector<int>);
void displayDe(unsigned int, unsigned int);

int main()
{
  unsigned int d = 7;           // start from 7
  unsigned int maxLen = 6;
  unsigned int v = 7;
  const unsigned int LIMITED = 1000; // < 1000
  for (; d < LIMITED; d++)
    {
      unsigned  int len = getLen(d);

      if (len > maxLen)
        {
          v =  d;
          maxLen = len;
        }
    }
  cout << "The value is " << v << endl
       << "And longest recurring cycle is " << maxLen << endl;

  return 0;
}

unsigned int getLen(unsigned int n)
{
  vector<int> v;
  unsigned int loop = 0;
  unsigned int mod = 10;
  unsigned int left;
  vector<int>::iterator it, it1;
  unsigned len = 0;
  while (loop < 3)
    {
      loop = 0;
      left = mod / n;
      mod %= n;
      mod *= 10;
      unsigned int tmpLeft = left;
      unsigned int tmpMod = mod;
      len = 0;
      for (it = v.begin(), it1 = it; it != v.end(); it++)
        {
          if (tmpLeft == *it)
            {
              tmpLeft = tmpMod / n ;
              tmpMod %= n;
              tmpMod *= 10;
              len++;
            }
          else
            {
              len = 0;
              tmpLeft = left;
              tmpMod = mod;
              it = it1;
              it1++;
            }
        }

      if (len > 0)
        {
          
          unsigned int i = 0;
          unsigned int ll, mm;
          for (; i < len; i++)
            {
              ll = left;
              mm = mod;
              v.push_back(left);
              left = mod / n;
              mod %= n;
              mod *= 10;
            }
          loop++;
          
          tmpLeft = left;
          tmpMod = mod;
          
          left = ll;
          mod = mm;
          while (loop < 3)
            {
              for (i = 0; i < len; i++)
                {
                  if (tmpLeft != v[v.size() - len + i])
                    break;
                  tmpLeft = tmpMod / n ;
                  tmpMod %= n;
                  tmpMod *= 10;
                }
              if (i == len)
                loop++;
              else
                break;
            }
        }
      else 
         v.push_back(left);
    }
  return len;
}

void display(vector<int> v)
{
  cout <<"*";

  for (int i = 0; i < v.size(); i++)
    cout <<v[i];
  cout << "*\n";
}

void displayDe(unsigned int n, unsigned int num = 30)
{
  unsigned mod = 10;
  unsigned left = 0;
  cout << "*";

  for (int i = 0; i < num; i++)
    {
      left = mod / n;
      mod %= n;
      mod *= 10;
      cout << left;
    }

  cout << "*\n";
}
