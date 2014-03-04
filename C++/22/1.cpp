#include<fstream>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstdlib>
#include<vector>

using std::ifstream;
using std::string;
using std::vector;

void split(int, int, vector<string> &, int &);
void quickSort(int, int, vector<string> &);

int main()
{
  ifstream in("names.txt");

  if(in.fail())
    {
      std::cerr << "Open failed.\n";
      exit(1);
    }
  
  string s;
  vector<string> v;
  while(std::getline(in, s, ','))
      v.push_back(s.substr(1, s.size() - 2));
  std::sort(v.begin(),v.end());	
  //  quickSort(0, v.size() - 1, v); 
  long long sum = 0;
  for(int i = 0; i < v.size(); i++)
    {
      int sumT = 0;
      s = v[i];
      for(int j = 0; j < s.size(); j++)
	sumT += s[j] - 'A' + 1;
      sum += sumT * (i + 1);
    }
  std::cout << sum << std::endl;
  return 0;
}

void split(int low, int high, vector<string> &v, int &w)
{
  string x = v[low];
  int  j = low;
  for(int i = low + 1; i <= high; i++)
    {
      if(v[i] < x)
	{
	  if (++j != i)
	    {
	      string temp = v[i];
	      v[i] = v[j];
	      v[j] = temp;
	    }
	}
    }
  string temp = v[j];
  v[j] = v[low];
  v[low] = temp;
  w = j;
}

void quickSort(int low, int high, vector<string> &v)
{
  if(low < high)
    {
      int w = -1;
      split(low, high, v, w);
      quickSort(low, w - 1, v);
      quickSort(w + 1, high, v);
    }
}
