//2013/5/13 by kevin
#include<cstdlib>
#include<vector>
#include<iostream>
#include<fstream>


int main()
{
  std::ifstream in("triangle.txt",std::ios::ate);
  if(in.fail())
    exit(1);
  int n = 0;
  int s = 100;
  int index = 0;
  std::vector<int> v,v1;
  in.seekg(-1, std::ios::cur);
  int  i = 0;

  //read in last s numbers
  while(in.seekg(-2, std::ios::cur))
    {
      in >> n;
      index++;
      v.push_back(n);
      in.seekg(-3, std::ios::cur);
      if (index ==  s)
      	{
      	  index = 0;
      	  s--;
	  break;
      	}
    }
  
  while(s >= 1)
    {
      v.resize(s + 1);
      v1.clear();
      while(in.seekg(-2, std::ios::cur))
	{
	  in >> n;
	  v1.push_back(n);
	  index++;
	  in.seekg(-3, std::ios::cur);
	  if (index ==  s)
	    {
	      index = 0;
	      s--;
	      break;
	    }
	}
      for(i = 0; i < s + 1; i++)
	{
	  int t1 = v1[i] + v[i];
	  int t2 = v1[i] + v[i + 1];
	  v[i] = t1 > t2?t1:t2;
	}
    }
  
  std::cout << v[0] << std::endl;
  return 0;
}


