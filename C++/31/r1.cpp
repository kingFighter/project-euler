// Recursion
#include <iostream>

using namespace std;
int getWays(int target, int n);

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
  
  int amount = 200;
  cout << getWays(200, 7) << endl;
  return 0;
}

int getWays(int target, int n) {
  if (n <= 0)
    return 1;
  int r = 0;
  while (target >= 0) {
    r += getWays(target, n - 1);
    target = target - coins[n];
}
  return r;
}
