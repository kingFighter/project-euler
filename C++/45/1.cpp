#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long int n = 286;
  long long int t, p, h;
  int flag = 0;
  
  while(flag < 2) {
    t = n * (n + 1) / 2;
    long long int p = sqrt(1 + 24 * t);
    if (p * p == (1 + 24 * t)) {
      if ((1 + p) % 6 == 0) {
        flag++;
      }
      else  {
        n++;
        continue;
      }
    } else {
      n++;
      continue;
    }

    long long int q = sqrt(1 + 8 * t);
    if (q * q == (1 + 8 * t)) {
      if ( (1 + q) % 4 == 0)
        flag++;
      else 
        flag = 0;
    } else {
      flag = 0;
    }
    n++;
  }
  cout << t << endl;
  return 0;
}
