// 2013/6/8 by kevin
#include<set>
#include<iostream>
#include<cmath>

using std::set;

int main()
{
  const int begin = 2;
  const int end = 100;
  set<double> s;

  for (int i = begin; i <= end; i++)
    for (int j = begin; j <= end; j++)
      s.insert(pow(static_cast<double>(i), j));
  
  std::cout << s.size() << std::endl;
  return 0;
}
