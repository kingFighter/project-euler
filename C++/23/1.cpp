// 2013/6/9 by kevin
#include<set>
#include<cmath>
#include<iostream>

using std::set;

int getDivisorsSum(int);

int main()
{
  set<int> s;
  set<int>::iterator p,pp;
  const int upLimit = 28123;
  bool abundantsSums[upLimit] = {false};
  int sum = 0;
  
  for (int i = 1; i <= upLimit; i++)
    {
      if (getDivisorsSum(i) > i)
	s.insert(i);
      sum += i;
    }
  
  int abundantsSum = 0;
  for (p = s.begin(); p != s.end(); p++)
    for (pp = p; pp != s.end(); pp++)
      {
	int temp = *p + *pp;
	if (temp <= upLimit && !abundantsSums[temp - 1])
	  {
	    abundantsSum += temp;
	    abundantsSums[temp - 1] = true;
	  }
      }
  
  std::cout << sum - abundantsSum << std::endl;

  return 0;
}

int getDivisorsSum(int n)
{
  int sum = 0;
  int mi = static_cast<int>(sqrt(n));
  for (int i = 1; i <= mi; i++)
    if (n % i == 0)
      sum += (i + n / i);
  
  if (mi * mi == n)
    sum -= mi;
  
  return sum - n;
}
