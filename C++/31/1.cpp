// Recursion
#include <iostream>

int getWays(int, int);

using namespace std;

int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};

int main() {
  cout << getWays(200, 0) << endl;
  return 0;
}

int getWays(int money, int maxCoin) {
  int sum = 0;
  if (maxCoin == 7)
    sum = 1;
  else {
    for (int i = maxCoin; i < 8; i++) {
      if (money - coins[i] == 0) sum++;
      if (money - coins[i] > 0) sum += getWays(money - coins[i], i);
    }
  }
  return sum;
}
