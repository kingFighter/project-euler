// Brute Force
#include <iostream>

using namespace std;

int main() {
  int target  = 200;
  int ways = 0;
  int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};

  for (int a = target; a >= 0; a -= coins[0]) {
    for (int b = a; b >= 0; b -= coins[1]) {
      for (int c = b; c >= 0; c -= coins[2]) {
        for (int d = c; d >= 0; d -= coins[3]) {
          for (int e = d; e >= 0; e -= coins[4]) {
            for (int f = e; f >= 0; f -= coins[5]) {
              for (int g = f; g >= 0; g -= coins[6]) {
                ways++;
              }
            }
          }
        }
      }
    }
  }
  cout << ways << endl;
  return 0;
}
