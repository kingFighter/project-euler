#include<iostream>

int main()
{
  int monthOfDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year = 1901;
  int month = 1;
  int count = 0;

  int numOfDay = 2;
  //We count during the twentieth century
  while(year <= 2000)
    {
      if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	monthOfDay[1] = 29;
      else
	monthOfDay[1] = 28;
      while(month <= 12)
	{
	  //just test the first of day
	  numOfDay += monthOfDay[month - 1];
	  //if it is Sunday?
	  if((numOfDay %= 7) == 0)
	    count++;
	  month++;
	}
      month = 1;
      year++;
    }

  std::cout << count << std::endl;
}
