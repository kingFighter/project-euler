// By Keivn
// 2013/8/28
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

using std::string;
using std::stringstream;

// get ith number
int getIthNum(int);
// get number n's pos
// like 10:11, 11:13
int getNumPos(int);

int main()
{
  int result = 1;
  for (int i = 0, j = 1; i < 7; i++, j *= 10)
      result *= getIthNum(j);

  std::cout << result << std::endl;
  return 0;
}

int getNumPos(int n)
{
  stringstream stream;
  string str;

  stream << n;
  stream >> str;
  int pos = str.size() * (n - static_cast<int>(pow(10, str.size() -  1)) + 1);
  for (int i = 1; i < str.size(); i++)
    pos += i * (static_cast<int>(pow(10, i) - pow(10, i - 1)));

  return pos;
}

int getIthNum(int n)
{
  int first = 1;
  int second = n;
  int mid, m;
  while(first <= second)
    {
      mid = (first + second) / 2;
      m = getNumPos(mid);
      if (m == n)
	return (mid % 10);
      else if (m > n)
	second = mid -1;
      else
	first = mid + 1;
    }
  if (m < n)
    mid++;
  stringstream ss;
  ss << mid;
  string str;
  ss >> str;
  if (m < n)
    return str[n - m - 1] - '0';
  return str[str.size() - 1 - (m - n)] - '0';
}

