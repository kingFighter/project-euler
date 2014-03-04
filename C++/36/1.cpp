// 2013/6/10 by Kevin
#include<iostream>
#include<bitset>
#include<sstream>

using std::stringstream;
using std::string;

const int UP_LIMIT = 1000000;

bool isPalindromic(int);
bool isPalindromicDec(int);
bool isPalindromicBin(int);
bool isPalindromic(int, int);
int makePalindromicBase2(int, bool);

void method1();
void method2();
void method3();

int main()
{
  method1();
  method2();
  method3();
  
  return 0;
}

bool isPalindromicDec(int n)
{
  
  stringstream ss;
  ss << n;
  string s;
  ss >> s;
  
  int len = s.length();
  int lenHalf = len / 2;
  
  int i = 0;
  while (i < lenHalf)
    {
      if (s[i] != s[len - i - 1])
	return false;
      i++;
    }
  return true;
}

bool isPalindromicBin(int n)
{
  std::bitset<32> nn(n);
  int  i = 31;
  
  while(i >= 0 && nn[i] == 0)
    i--;
  
  int end = (i + 1) / 2;

  int j = 0;
  while(j < end)
    {
      if (nn[i] != nn[j])
	return false;
      i--;
      j++;
    }

  return true;
}

bool isPalindromic(int n)
{
  return (isPalindromicDec(n) && isPalindromicBin(n));
}

bool isPalindromic(int n, int base)
{
  int reversed = 0;
  int k = n;
  while (k > 0)
    {
      reversed = base * reversed + k % base;
      k /= base;
    }
  return reversed == n;

}

void method1()
{
  int sum = 0;
  
  for (int i = 1; i < UP_LIMIT; i += 2)
    if (isPalindromic(i))	
      sum += i;
 
  std::cout << "Method1: " << sum << std::endl; 

}

void method2()
{
  int sum = 0;
  
  for (int i = 1; i < UP_LIMIT; i += 2)
    if (isPalindromic(i, 2) && isPalindromic(i, 10))	
      sum += i;
 
  std::cout << "Method2: " << sum << std::endl; 

}

//n xyz
//type true:xyzyx false: xyzzyx
int makePalindromicBase2(int n, bool type)
{
  int res = n;
  if (type) 
    n = n >> 1;
  while(n > 0)
    {
      res = (res << 1) + (n & 1);
      n >>= 1;
    }
  return res;
}

void method3()
{
  int sum = 0;
  int i = 1;
  int checkNum;
  while(1)
    {
      checkNum = makePalindromicBase2(i, true);
      if (checkNum >= UP_LIMIT)
	break;
      else if(isPalindromic(checkNum, 10))
	sum += checkNum;

      checkNum = makePalindromicBase2(i, false);
      if (checkNum >= UP_LIMIT)
	break;
      else if(isPalindromic(checkNum, 10))
	sum += checkNum;

      i++;
    }
  std::cout << "Method3: " << sum << std::endl; 
}
