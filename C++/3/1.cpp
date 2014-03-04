#include <iostream>
#include<cmath>
using std::cout;
using std::endl;

int main()
{
   long long n = 600851475143LL;
   int maxPrimeFactor = 1;
   if (n % 2 == 0)
   {
     n /= 2;
     maxPrimeFactor = 2;
     while(n % 2 == 0)
       n /= 2;
   }
   int factor = 3;
   int limit = sqrt(n);
   while( n > 1 && factor <= limit)
   {
     if (n % factor == 0)
     {
       n /= factor;
       maxPrimeFactor = factor;
       while(n % factor == 0)
         n /= factor;
       limit = sqrt(n);
     }
     factor += 2;
   }
   if (n == 1) 
   	cout << maxPrimeFactor;
   else
     cout << n;
    
   return 0;
}
   